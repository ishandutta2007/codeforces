#include<cstdio>
#include<queue>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,m,a[N],t;
int b[N],tot;
struct Node {
	int tim,val;
	bool operator < (const Node &o) const {
		return tim>o.tim;
	}
};
priority_queue<Node> pq1,pq2;
int chk(int lim) {
	while(pq1.size()) pq1.pop();
	while(pq2.size()) pq2.pop();
	fr(i,1,lim) pq2.push(Node{b[i]>>1,b[i]});
	int now=0;
	while(pq1.size()||pq2.size()) {
		++now;
		if(pq1.size()&&(pq2.empty()||pq2.top()<pq1.top())) {
			if(pq1.top().tim<now) return 0;
			pq1.pop();
		} else {
			Node tmp=pq2.top(); pq2.pop();
			pq1.push(Node{tmp.val-2*(now-1)-1+now,0});
		}
	}
	return 1;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>m;
		fr(i,1,m) cin>>a[i];
		sort(a+1,a+m+1);
		tot=0;
		fr(i,2,m) b[++tot]=a[i]-a[i-1]-1;
		b[++tot]=a[1]+n-a[m]-1;
		sort(b+1,b+tot+1,greater<int>());
		int l=0,r=tot;
		while(l<r) {
			int mid=l+r+1>>1;
			if(chk(mid)) l=mid;
			else r=mid-1;
		}
		ll ans=0,sum=0;
		fr(i,0,l) {
			sum+=b[i];
			ans=max(ans,sum-1ll*(2*i)*(2*i-1)/2+(i<m&&b[i+1]-4*i>0));
		}
		cout<<n-ans<<endl;
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}
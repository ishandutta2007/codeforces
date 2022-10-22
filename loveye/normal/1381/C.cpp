#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int t,n,x,y,b[N],a[N],tmp[N],tot;
int cnt[N];
struct Node {
	int i,c;
	bool operator < (const Node &o) const {
		return c<o.c;
	}
};
priority_queue<Node> pq;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>x>>y;
		while(pq.size()) pq.pop();
		fr(i,1,n+1) cnt[i]=0;
		fr(i,1,n) {
			cin>>b[i]; a[i]=0;
			pq.push((Node){i,++cnt[b[i]]});
		}
		int emp;
		fr(i,1,n+1) if(cnt[i]==0) emp=i;
		fr(i,1,x) {
			Node now=pq.top(); pq.pop();
			a[now.i]=b[now.i];
		}
		fr(i,1,n+1) cnt[i]=0;
		tot=0;
		fr(i,1,n) if(!a[i]) ++cnt[b[i]],tmp[++tot]=i;
		sort(tmp+1,tmp+tot+1,[](const int &i,const int &j) {
			return b[i]<b[j];
		});
		int sft=tot>>1,res=n-y;
		fr(i,1,tot) a[tmp[(i+sft-1)%tot+1]]=b[tmp[i]];
		fr(i,1,tot) if(a[tmp[i]]==b[tmp[i]]) {
			if(res) a[tmp[i]]=emp,--res;
			else {res=-1; break;}
		}
		if(res<0) cout<<"NO"<<endl;
		else {
			fr(i,1,tot) if(res&&a[tmp[i]]!=emp) a[tmp[i]]=emp,--res;
			cout<<"YES"<<endl;
			fr(i,1,n) cout<<a[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}
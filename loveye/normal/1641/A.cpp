#include<cstdio>
#include<map>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n,a[N],x;
map<int,int> cnt;
signed main() {
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--) {
		cin>>n>>x;
		cnt.clear();
		fr(i,1,n) cin>>a[i],++cnt[a[i]];
		int ans=0;
		for(auto &p:cnt) if(cnt.count(p.first*x)) {
			int y=p.first*x,d=min(cnt[y],p.second);
			cnt[y]-=d;
			p.second-=d;
			ans+=d;
		}
		cout<<n-ans*2<<endl;
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
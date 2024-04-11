#include<cstdio>
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
int n,a[N],b[N],p[N];
vector<int> tmp;
int vis[N];
int main() {
	int T=read();
	while(T--) {
		n=read();
		fr(i,1,n) a[i]=read(),vis[i]=0;
		fr(i,1,n) b[i]=read(),p[a[i]]=b[i];
		tmp.clear();
		fr(i,1,n) if(!vis[i]) {
			int len=0,cur=i;
			do vis[cur]=1,cur=p[cur],++len;
			while(cur!=i);
			tmp.push_back(len);
		}
		sort(tmp.begin(),tmp.end(),greater<int>());
		int res=n; ll ans=0;
		for(auto x:tmp) {
			int z=x/2;
			fr(i,1,z-1) ans+=2*i*2;
			ans+=(z*2)*(res-z+1-z);
			res-=z<<1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}
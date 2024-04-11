#include<cstdio>
#include<cmath>
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

const int N=2e5+5,M=1e6+5;
int t;
int n,e,a[N],b[N],tot;
int p[M]; bool np[M];
void sieve() {
	n=1e6;
	np[1]=1;
	fr(i,2,n) {
		if(!np[i]) p[++p[0]]=i;
		for(int j=1;j<=p[0]&&i*p[j]<=n;++j) {
			np[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int chk(int x) {return x==1||!np[x];}
int main() {
	sieve();
	cin>>t;
	while(t--) {
		cin>>n>>e;
		fr(i,1,n) cin>>a[i];
		ll ans=0;
		fr(i,1,e) {
			tot=0;
			for(int j=i;j<=n;j+=e) b[++tot]=a[j];
			int lstp2=0,lstp=0;
			fr(j,1,tot) {
				if(!chk(b[j])) lstp2=lstp=j;
				else {
					if(!np[b[j]]) lstp2=lstp,lstp=j;
					int dt=lstp-(lstp==j)-lstp2;
					if(dt>0) ans+=dt;
				}
			}
		}
		cout<<ans<<endl;
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
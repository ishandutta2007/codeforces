#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e6+5,MOD=1e9+7;
int n;
ll pw[N],f[N],s[N],pw2[N];
int main() {
	int T=read();
	while(T--) {
		n=read();
		if(n==1) {puts("1"); continue;}
		*pw=1; fr(i,1,n) pw[i]=pw[i-1]*(MOD+1>>1)%MOD;
		*pw2=1; fr(i,1,n) pw2[i]=pw2[i-1]*2%MOD;
		f[n]=1; s[n]=pw[n]; s[n+1]=0;
		rf(i,n-1,2) {
			f[i]=(s[i+1]-s[min(2*i,n+1)])*pw2[i]%MOD;
			s[i]=(s[i+1]+f[i]*pw[i])%MOD;
		}
		puts("0");
		fr(i,2,n) {
			int res=i+1>>1;
			printf("%lld\n",(pw[res-1]*f[i]%MOD+MOD)%MOD);
		}
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}
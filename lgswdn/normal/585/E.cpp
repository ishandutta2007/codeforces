#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int M=1e6+9,N=1e7+9,mod=1e9+7;
int n,c[N],a[M],m,p[N],q[N],r[N],mu[N],vst[N],mx;
long long b[M];
int pr[M],tot;

void sieve() {
	mu[1]=1;
	rep(i,2,mx) {
		if(!vst[i]) pr[++tot]=i, mu[i]=-1;
		for(int j=1;j<=tot&&i*pr[j]<=mx;j++) {
			vst[i*pr[j]]=1;
			if(i%pr[j]==0) {mu[i*pr[j]]=0; break;}
			mu[i*pr[j]]=-mu[i]; 
		}
	}
}
void sir(int *a) {
	rep(i,1,tot) for(int j=mx/pr[i];j;j--) a[j]+=a[j*pr[i]];
}
void dir(int *a) {
	rep(i,1,tot) for(int j=1;j*pr[i]<=mx;j++) a[j*pr[i]]+=a[j];
}
void ris(int *a) {
	per(i,tot,1) for(int j=1;j*pr[i]<=mx;j++) a[j]=(a[j]+mod-a[j*pr[i]])%mod;
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read(), c[a[i]]++, mx=max(mx,a[i]);
	sieve();
	b[0]=1; rep(i,1,n) b[i]=b[i-1]*2%mod;
	sir(c);
	rep(i,1,mx) p[i]=mu[i]*c[i];
	dir(p);
	rep(i,1,mx) q[i]=b[c[i]]-1;
	ris(q);
	int ans=0;
	rep(i,2,mx) ans=(ans+1ll*p[i]*q[i])%mod;
	printf("%lld\n",ans);
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9,mod=998244353;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,m,pl[N],prr[N],l[N],r[N],f[N],s[N],pr[N],cnt,mu[N],vst[N],ans;

void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vst[i]) pr[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
			vst[i*pr[j]]=1;
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
            mu[i*pr[j]]=-mu[i];
		}
	}
}

signed main() {
	n=read(), m=read();
	sieve(m);
	rep(i,1,n) pl[i]=read(), prr[i]=read();
	rep(d,1,m) if(mu[d]) {
		rep(i,1,n) l[i]=(pl[i]+d-1)/d, r[i]=prr[i]/d;
		int nm=m/d;
		rep(j,0,nm) s[j]=1;
		rep(i,1,n) {
			rep(j,1,nm) f[j]=0;
			rep(j,l[i],nm) {
				f[j]=s[j-l[i]];
				if(j-r[i]-1>=0) f[j]=(f[j]+mod-s[j-r[i]-1])%mod;
			}
			s[0]=0;
			rep(j,1,nm) s[j]=(s[j-1]+f[j])%mod;
		}
		ans=(ans+mu[d]*s[nm])%mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
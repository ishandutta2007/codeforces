#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=309,mod=1e9+7;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

void pls(int &x,int y) {x+=y; x=(x>=mod?x-mod:x);}

int n,a[N],s[N],fac[N],inv[N],ifac[N];

void pre() {
	inv[0]=inv[1]=fac[0]=ifac[0]=1;
	rep(i,1,n) fac[i]=fac[i-1]*i%mod;
	rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,1,n) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
	if(x<0||y<0||x<y) return 0;
	else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

namespace Solution_1 {
	int s[N],f[2][N][N];
	void solve() {
		int d=0;
		rep(i,1,n) {
			if(a[i]==a[i-1]) s[i]=s[i-1]+1;
			else s[i]=0;
		}
		f[0][0][0]=1;
		rep(i,1,n) {
			if(a[i]!=a[i-1]) {
				rep(j,0,i) rep(k,1,s[i-1])
					pls(f[d^1][j][0],f[d^1][j][k]), f[d^1][j][k]=0;
			}
			rep(j,0,i) {
				int upk=min(s[i],j);
				rep(k,0,upk) {
					if(j&&k) pls(f[d][j][k],f[d^1][j-1][k-1]*(2*s[i]-k+1)%mod);
					pls(f[d][j][k],f[d^1][j][k]*(i-2*s[i]+2*k-j)%mod);
					pls(f[d][j][k],f[d^1][j+1][k]*(j-k+1)%mod);
				}
			}
			memset(f[d^1],0,sizeof(f[d^1]));
			if(i!=n) d^=1;
		}
		printf("%lld\n",f[d][0][0]);
	}
}

namespace Solution_2 {
	int cnt,s[N],g[N][N],f[N][N];
	void calc_g() {
		g[0][0]=1;
		rep(i,1,n) rep(j,1,i) g[i][j]=((i+j-1)*g[i-1][j]+j*g[i-1][j-1])%mod;
	}
	void calc_f() {
		int q=0;
		f[0][0]=1;
		rep(i,1,cnt) {
			rep(j,0,q) rep(k,1,s[i]) rep(p,0,j) {
				pls(f[i][j+s[i]-k-p],C(j,p)*C(q+1-j,k-p)%mod*g[s[i]][k]%mod*f[i-1][j]%mod);
			}
			q+=s[i];
		}
	}
	void solve() {
		rep(i,1,n) {
			if(a[i]!=a[i-1]) {
				s[++cnt]=1;
			} else {
				s[cnt]++;
			}
		}
		calc_g();
		calc_f();
		printf("%lld\n",f[cnt][0]);
	}
}

namespace Solution_3 {
	int cnt,s[N],f[N][N];
	void solve() {
		rep(i,1,n) {
			if(a[i]!=a[i-1]) {
				s[++cnt]=1;
			} else {
				s[cnt]++;
			}
		}
		int mxr=0;
		f[0][0]=1;
		rep(i,1,cnt) {
			mxr+=s[i]-1;
			rep(j,0,mxr) {
				int upk=min(s[i],j);
				rep(k,0,upk) 
					pls(f[i][j],f[i-1][j-k]*C(s[i]-1,k)%mod*ifac[s[i]-k]%mod);
			}
		}
		int ans=0;
		rep(i,0,mxr) pls(ans,f[cnt][i]*fac[n-i]%mod*(i%2==0?1:mod-1)%mod);
		rep(i,1,cnt) ans=ans*fac[s[i]]%mod;
		printf("%lld\n",ans);
	} 
}

signed main() {
	n=read();
	rep(i,1,n) {
		a[i]=read();
		for(int j=2;j*j<=a[i];j++)
			while(a[i]%(j*j)==0) a[i]/=j*j;
	}
	sort(a+1,a+n+1);
	pre();
	Solution_3::solve();
	return 0;
}
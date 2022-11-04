#include<bits/stdc++.h>
#define int long long
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

const int N=3e5+9,mod=1e9+7;

int n,a[N],fac[N],inv[N],ifac[N],cs[N],mx,cnt[N],c[N],d[N],ans;
bool vst[N];

int ksm(int x,int y,int res=1) {
    for(;y;y>>=1,x=x*x%mod) if(y%2==1) res=res*x%mod;
    return res;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void pre() {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    ifac[n]=ksm(fac[n],mod-2);
    per(i,n-1,1) ifac[i]=ifac[i+1]*(i+1)%mod;
    rep(i,2,n) inv[i]=ifac[i]*fac[i-1]%mod;
    cs[0]=C(n-1,0);
    rep(i,1,n-1) cs[i]=(cs[i-1]+C(n-1,i))%mod;
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read(), mx=max(mx,a[i]), c[a[i]]++;
	pre();
	rep(p,2,mx) if(!vst[p]) { 
		cnt[p]=1; int tot=0;
		rep(i,1,20) d[i]=0;
		for(int v=p;v<=mx;v+=p) {
			vst[v]=1;
			if((v/p)%p==0) cnt[v]=cnt[v/p]+1;
			else cnt[v]=1;
			d[cnt[v]]+=c[v], tot+=c[v];
		}
		int pos=n-tot,res=0;
		rep(i,1,20) {
			rep(j,1,d[i]) {
				pos++;
				res=(res-i*(cs[n-1]-cs[pos-1]-cs[pos-2])%mod+mod)%mod;
			}
		}
		ans=(ans+res)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
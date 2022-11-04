#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=500009, mod=998244353;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N];

/*
bool ch[N];
int aa[N],bb[N],tota,totb;
void calc() {
	tota=totb=0;
	rep(i,1,2*n) if(ch[i]) aa[++tota]=a[i];
	rep(i,1,2*n) if(!ch[i]) bb[++totb]=a[i];
	if(tota!=totb) return;
	sort(aa+1,aa+n+1);
	sort(bb+1,bb+n+1);
	reverse(bb+1,bb+n+1);
	int sum=0;
	rep(i,1,n) printf("%lld ",aa[i]); puts("");
	rep(i,1,n) printf("%lld ",bb[i]); puts("");
	rep(i,1,n) sum+=abs(aa[i]-bb[i]);
	printf("%lld\n",sum); puts("");
}
void dfs(int pos) {
	if(pos==2*n+1) {calc(); return;}
	ch[pos]=0, dfs(pos+1);
	ch[pos]=1, dfs(pos+1);
}
*/

int mn,fac[N], inv[N], ifac[N];
void pre() {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    for(int i=1;i<=mn;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<=mn;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=1;i<=mn;i++) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main() {
	n=read();
	rep(i,1,2*n) a[i]=read();
	sort(a+1,a+2*n+1);
	int ans=0;
	rep(i,1,n) (ans+=abs(a[2*n-i+1]-a[i]))%=mod;
	mn=2*n;
	pre();
	ans=ans*C(2*n,n)%mod;
	printf("%lld\n",ans);
	return 0;
}
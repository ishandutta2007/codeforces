#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9, mod=998244353;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,inv[N],fac[N],ifac[N],ans;
char s[N];

void pre() {
	inv[0]=inv[1]=fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,2,n) fac[i]=fac[i-1]*i%mod;
	rep(i,2,n) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
	if(x<0||y<0||x<y) return 0;
	else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	pre();
	int l=0,r=0,x=0,y=0;
	per(i,n,1) {
		if(s[i]=='?') r++;
		else if(s[i]==')') y++;
	}
	rep(pos,1,n-1) {
		if(s[pos]=='?') l++, r--;
		else if(s[pos]==')') y--;
		else x++;
		ans=(ans+x*C(l+r,r+y-x)%mod+l*C(l+r-1,r+y-x-1)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
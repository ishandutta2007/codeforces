#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],f[N][N][N];
char s[N];
bool vst[N][N][N];

int dp(int l,int r,int k) {
	if(vst[l][r][k]) return f[l][r][k]; vst[l][r][k]=1;
	if(l>r) return f[l][r][k]=0;
	if(l==r) return f[l][r][k]=a[k+1];
	f[l][r][k]=dp(l+1,r,0)+a[k+1];
	rep(p,l+1,r) if(s[l]==s[p]) f[l][r][k]=max(f[l][r][k],dp(l+1,p-1,0)+dp(p,r,k+1));
	return f[l][r][k];
}

signed main() {
	scanf("%lld%s",&n,s+1);
	rep(i,1,n) a[i]=read();
	rep(i,1,n) rep(j,1,i-1) a[i]=max(a[i],a[j]+a[i-j]);
	printf("%lld\n",dp(1,n,0));
	return 0;
}
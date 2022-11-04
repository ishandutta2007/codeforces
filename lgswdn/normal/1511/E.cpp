#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=3e5+9,mod=998244353;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,ct,pw[N],f[N],ans;
vector<char>c[N];
char tmp[N];

signed main() {
	n=read(), m=read();
	rep(i,1,n) {
		scanf("%s",tmp+1);
		c[i].push_back(0);
		rep(j,1,m) c[i].push_back(tmp[j]);
	}
	pw[0]=1;
	rep(i,1,n*m) pw[i]=pw[i-1]*2%mod;
	rep(i,2,n*m) f[i]=(f[i-1]+2*f[i-2]+pw[i-2])%mod;
	rep(i,1,n) rep(j,1,m) if(c[i][j]=='o') ct++;
	rep(i,1,n) {
		int l=1;
		while(l<=m&&c[i][l]=='*') l++;
		rep(r,l,m) if(r==m&&c[i][r]=='o'||c[i][r+1]=='*') {
			int len=r-l+1;
			ans=(ans+f[len]*pw[ct-len])%mod;
			l=r+1; while(l<=m&&c[i][l]=='*') l++;
			r=l-1;
		}
	}
	rep(i,1,m) {
		int l=1;
		while(l<=n&&c[l][i]=='*') l++;
		rep(r,l,n) if(r==n&&c[r][i]=='o'||c[r+1][i]=='*') {
			int len=r-l+1;
			ans=(ans+f[len]*pw[ct-len])%mod;
			l=r+1; while(l<=n&&c[l][i]=='*') l++;
			r=l-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
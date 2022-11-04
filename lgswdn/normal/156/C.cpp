#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109,M=2609,mod=1000000007;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,f[N][M];
char c[N];

signed main() {
	T=read();
	f[0][0]=1;
	rep(i,1,100) {
		rep(j,1,2600) {
			rep(k,1,min(j,26ll)) {
				f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
			}
		}
	}
	while(T--) {
		scanf("%s",c+1);
		int n=strlen(c+1),sum=0;
		rep(i,1,n) sum+=c[i]-'a'+1;
		printf("%lld\n",f[n][sum]-1);
	}
	return 0;
}
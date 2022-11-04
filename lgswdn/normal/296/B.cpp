#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9,mod=1e9+7;

int n,f[N][2][2];
char a[N],b[N];

signed main() {
	scanf("%lld%s%s",&n,a+1,b+1);
	f[0][0][0]=1;
	rep(i,1,n) {
		if(isdigit(a[i])&&isdigit(b[i])) {
			if(a[i]<b[i]) {
				f[i][1][0]=(f[i-1][0][0]+f[i-1][1][0])%mod;
				f[i][1][1]=(f[i-1][0][1]+f[i-1][1][1])%mod;
			} else if(a[i]>b[i]) {
				f[i][0][1]=(f[i-1][0][0]+f[i-1][0][1])%mod;
				f[i][1][1]=(f[i-1][1][0]+f[i-1][1][1])%mod;
			} else {
				f[i][0][0]=f[i-1][0][0], f[i][1][1]=f[i-1][1][1];
				f[i][1][0]=f[i-1][1][0], f[i][0][1]=f[i-1][0][1];
			}
		} else if(!isdigit(a[i])&&!isdigit(b[i])) {
			f[i][0][0]=f[i-1][0][0]*10%mod;
			f[i][1][0]=(f[i-1][1][0]*55+f[i-1][0][0]*45)%mod;
			f[i][0][1]=(f[i-1][0][1]*55+f[i-1][0][0]*45)%mod;
			f[i][1][1]=(f[i-1][1][1]*100+f[i-1][1][0]*45+f[i-1][0][1]*45)%mod;
		} else if(isdigit(a[i])&&!isdigit(b[i])) {
			int r=a[i]-'0'+1;
			f[i][0][0]=f[i-1][0][0];
			f[i][1][0]=(f[i-1][1][0]*(11-r)+f[i-1][0][0]*(10-r))%mod;
			f[i][0][1]=(f[i-1][0][1]*r+f[i-1][0][0]*(r-1))%mod;
			f[i][1][1]=(f[i-1][1][1]*10+f[i-1][1][0]*(r-1)+f[i-1][0][1]*(10-r))%mod;
		} else if(!isdigit(a[i])&&isdigit(b[i])) {
			int r=b[i]-'0'+1;
			f[i][0][0]=f[i-1][0][0];
			f[i][1][0]=(f[i-1][1][0]*r+f[i-1][0][0]*(r-1))%mod;
			f[i][0][1]=(f[i-1][0][1]*(11-r)+f[i-1][0][0]*(10-r))%mod;
			f[i][1][1]=(f[i-1][1][1]*10+f[i-1][1][0]*(10-r)+f[i-1][0][1]*(r-1))%mod;
		}
		//printf("%lld %lld %lld %lld\n",f[i][0][0],f[i][0][1],f[i][1][0],f[i][1][1]); 
	}
	printf("%lld\n",f[n][1][1]);
	return 0;
}
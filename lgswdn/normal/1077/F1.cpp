#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=4009;

int n,k,m,a[N];

namespace f1 {
	int f[209][209];
	void main(){
		memset(f,128,sizeof(f));
		rep(i,0,k-1) f[i][0]=0;
		rep(j,1,m) rep(i,1,n) {
			rep(p,max(1ll,i-k+1),i)
				f[i][j]=max(f[i][j],f[p-1][j-1]+a[p]);
		}
		printf("%lld\n",max(-1ll,f[n][m]));
	}
}

signed main() {
	scanf("%lld%lld%lld",&n,&k,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	if(n<=200) f1::main();
	return 0;
}
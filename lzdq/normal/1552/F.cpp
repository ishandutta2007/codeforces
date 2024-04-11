#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353;
int n,x[MAXN],y[MAXN],s[MAXN];
int fa[MAXN],f[MAXN],g[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",x+i,y+i,s+i);
		fa[i]=lower_bound(x+1,x+i+1,y[i])-x;
		f[i]=(x[i]-y[i]+(g[i-1]-g[fa[i]-1]+mod)%mod)%mod;
		g[i]=(g[i-1]+f[i])%mod;
		if(s[i]) ans=(ans+f[i])%mod;
	}
	ans=(ans+x[n]+1)%mod;
	printf("%d\n",ans);
	return 0;
}
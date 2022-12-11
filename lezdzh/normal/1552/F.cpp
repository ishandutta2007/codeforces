#include<cstdio>
#include<algorithm>
using namespace std;

const int md=998244353;
long long x[200001],y[200001],op[200001],f[200001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&x[i],&y[i],&op[i]);
	for(int i=1;i<=n;i++){
		int w=lower_bound(x+1,x+n+1,y[i])-x;
		f[i]=((f[i-1]+f[i-1]-f[w-1]+x[i]-y[i])%md+md)%md;
	}
	long long ans=(x[n]+1)%md;
	for(int i=1;i<=n;i++)
		if(op[i])ans=(ans+f[i]-f[i-1]+md)%md;
	printf("%lld\n",ans);
}
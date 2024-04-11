#include<cstdio>

using namespace std;

int jc[250001];
int main(){
	int n,md;
	scanf("%d%d",&n,&md);
	for(int i=jc[0]=1;i<=n;i++)
		jc[i]=1ll*i*jc[i-1]%md;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*(n-i+1)*(n-i+1)%md*jc[n-i]%md*jc[i])%md;
	}
	printf("%d\n",ans);
}
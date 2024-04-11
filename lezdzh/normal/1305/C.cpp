#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001],b[1001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[i]=o;
		b[o%m]++;
		if(b[o%m]>=2){
			printf("0\n");
			return 0;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans=1ll*ans*abs(a[j]-a[i])%m;
	printf("%d\n",ans);
}
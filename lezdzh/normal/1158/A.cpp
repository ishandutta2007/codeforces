#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001],b[100001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	long long suma=0,sumb=0;
	for(int i=1;i<=n;i++)
		suma+=a[i];
	for(int i=1;i<=m;i++)
		sumb+=b[i];
	if(b[1]<a[n])printf("%d\n",-1);
	else if(b[1]==a[n])
		printf("%lld\n",suma*m+sumb-1ll*m*a[n]);
	else printf("%lld\n",suma*m+sumb-1ll*(m-1)*a[n]-a[n-1]);
}
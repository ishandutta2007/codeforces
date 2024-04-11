#include<cstdio>

using namespace std;

long long a[100001];
int z[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1){
		printf("1 1\n0\n1 1\n0\n1 1\n%lld\n",-a[1]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		z[1ll*i*(n-1)%n]=i;
	printf("%d %d\n",1,n-1);
	for(int i=1;i<=n-1;i++){
		int o=z[(n-a[i]%n+n)%n];
		a[i]+=1ll*o*(n-1);
		printf("%lld%c",1ll*o*(n-1),i==n-1?'\n':' ');
	}
	printf("%d %d\n",n,n);
	int o=(n-a[n]%n+n)%n;
	printf("%d\n",o);
	a[n]+=o;
	printf("%d %d\n",1,n);
	for(int i=1;i<=n;i++)
		printf("%lld%c",-a[i],i==n?'\n':' ');
}
#include<cstdio>

using namespace std;

int a[100001],b[100001];
int main(){
	int n;
	scanf("%d",&n);
	long long z=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0)a[i]/=2;
		else{
			if(a[i]<0)a[i]-=1;
			a[i]/=2;
			b[i]=1;
			b[0]++;
		}
		z+=a[i];
	}
	for(int i=1;i<=n;i++)
		if(z<0&&b[i]){
			a[i]++;
			z++;
		}
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
}
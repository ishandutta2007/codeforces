#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=1;i<n;i++)
			sum+=a[i];
		if(sum<a[n]){
			printf("T\n");
			continue;
		}
		printf((sum+a[n])%2?"T\n":"HL\n");
	}
}
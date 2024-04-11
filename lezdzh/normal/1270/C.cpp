#include<cstdio>

using namespace std;

int a[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		int o=0;
		long long s=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			o^=a[i];
			s+=a[i];
		}
		printf("2\n%d %lld\n",o,s+o);
	}
}
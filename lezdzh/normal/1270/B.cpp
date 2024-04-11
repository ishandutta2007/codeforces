#include<cstdio>
#include<algorithm>
using namespace std;

int a[200001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
			if(abs(a[i+1]-a[i])>=2){
				printf("YES\n%d %d\n",i,i+1);
				goto ok;
			}
		printf("NO\n");
ok:;
	}
}
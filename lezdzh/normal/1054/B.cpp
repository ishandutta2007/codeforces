#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,mx=-1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a<=mx+1)mx=max(mx,a);
		else{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
}
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n,a[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++)
			printf("%d ",a[n-i+1]);
		puts("");
	}
	return 0;
}
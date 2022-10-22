#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		printf("%d\n",n);
	}
	return 0;
}
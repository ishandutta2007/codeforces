#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int T,n,i,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		printf("%d\n",max(0,min(n-2,a[n-1]-1)));
	}
	//while(1);
}
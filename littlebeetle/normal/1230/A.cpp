#include<cstdio>
#include<algorithm>
using namespace std;
const int N=233;
int n,a[N],i;
int main(){
	n=4;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(a[n]==a[n-1]+a[n-2]+a[n-3]||a[n]+a[n-3]==a[n-1]+a[n-2])
		printf("YES");
	else
		printf("NO");
}
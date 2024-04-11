#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,i,a[N];
int main(){
	scanf("%d",&n);
	n*=2;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(a[1]==a[n])
		printf("-1");
	else
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
}
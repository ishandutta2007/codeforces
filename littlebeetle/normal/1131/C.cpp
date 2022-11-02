#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2000;
int n,i,a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i+=2)
		printf("%d ",a[i]);
	i=n>>1<<1;
	while(i)
		printf("%d ",a[i]),i-=2;
}
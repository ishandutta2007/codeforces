#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,a[N],k,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),k+=a[i]%2;
	if(k!=0&&k!=n)
		sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}
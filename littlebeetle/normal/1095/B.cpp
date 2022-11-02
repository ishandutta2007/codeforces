#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,a[N],i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	printf("%d",min(a[n-1]-a[1],a[n]-a[2]));
}
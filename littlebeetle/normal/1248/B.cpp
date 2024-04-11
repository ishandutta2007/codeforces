#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,a[N],s1,s2,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n/2;i++)
		s1+=a[i];
	for(;i<=n;i++)
		s2+=a[i];
	printf("%lld",1ll*s1*s1+1ll*s2*s2);
}
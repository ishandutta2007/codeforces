#include<cstdio>
const int N=1002;
typedef long long ll;
ll n,l,r,i,a[N],s;
int main(){
	scanf("%I64d%I64d%I64d",&n,&l,&r);
	for(i=1;i<=n-l+1;i++)
		a[i]=1;
	for(i=n-l+2;i<=n;i++)
		a[i]=a[i-1]*2;
	for(i=1;i<=n;i++)
		s+=a[i];
	printf("%I64d ",s);
	s=0;
	a[1]=1;
	for(i=2;i<=r;i++)
		a[i]=a[i-1]*2;
	for(i=r+1;i<=n;i++)
		a[i]=a[i-1];
	for(i=1;i<=n;i++)
		s+=a[i];
	printf("%I64d",s);
//(1);
}
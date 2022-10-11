#include <iostream>
#include <algorithm>
using namespace std;
long long sum,sum2;
int arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		sum+=(long long)i*arr[i]-sum2;
		sum2+=arr[i];
	}
	long long nom=2LL*sum+sum2,den=n;
	printf("%I64d %I64d",nom/__gcd(nom,den),den/__gcd(nom,den));
}
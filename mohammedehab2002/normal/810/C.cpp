#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define mod 1000000007
long long pow_log(long long n,long long exp)
{
    long long ret;
    if (exp==0)
    return 1;
    if (exp==1)
    return n;
    ret=pow_log(n,exp/2);
    if (exp%2==0)
    return (((ret%mod)*(ret%mod))%mod);
    else
    return ((((ret%mod)*(ret%mod))%mod)*n)%mod;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	long long sl=0,sr=0,ans=0;
	for (int i=0;i<n-1;i++)
	{
		sl=(sl+arr[i])%mod;
		sr=(sr+arr[n-i-1])%mod;
		ans=(ans+((((sr-sl+mod)%mod)*pow_log(2,i))%mod))%mod;
	}
	cout << ans;
}
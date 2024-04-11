#include <iostream>
using namespace std;
#define mod 1000000007
int arr[100005][2],cum[100005];
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
	long long m;
	scanf("%d%I64d",&n,&m);
	for (int x=0;x<2;x++)
	{
		for (int i=0;i<n;i++)
		scanf("%d",&arr[i][x]);
	}
	for (int i=n-1;i>=0;i--)
	cum[i]=cum[i+1]+(arr[i][0]==0)+(arr[i][1]==0);
	long long ans=0,carry=1;
	for (int i=0;i<n;i++)
	{
		long long tmp=(pow_log(m,cum[i+1])*carry)%mod;
		if (arr[i][0] && arr[i][1])
		{
			if (arr[i][0]>arr[i][1])
			{
				ans=(ans+tmp)%mod;
				break;
			}
			else if (arr[i][0]<arr[i][1])
			break;
		}
		else if (!arr[i][0] && arr[i][1])
		ans=(ans+(m-arr[i][1])*tmp)%mod;
		else if (arr[i][0] && !arr[i][1])
		ans=(ans+(arr[i][0]-1)*tmp)%mod;
		else
		{
			ans=(ans+((m*(m-1)/2)%mod)*tmp)%mod;
			carry=(carry*m)%mod;
		}
	}
	printf("%I64d",(ans*pow_log(pow_log(m,cum[0]),mod-2))%mod);
}
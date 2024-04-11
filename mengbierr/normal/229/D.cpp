#include <iostream>
using namespace std;
int n,H,f[5010],sum[5010],h[5010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>H;
		sum[i]=sum[i-1]+H;
	}
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			if(sum[i]-sum[j]>=h[j])
			{
				f[i]=f[j]+i-j-1;
				h[i]=sum[i]-sum[j];
				break;
			}
	cout<<f[n]<<endl;
}
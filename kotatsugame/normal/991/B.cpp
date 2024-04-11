#include<iostream>
using namespace std;
int n,a[6],sum,ans;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int b;cin>>b;
		sum+=b;
		a[b]++;
	}
	for(int i=2;i<5;i++)
	{
		while(a[i]>0&&2*sum<9*n)
		{
			ans++;
			sum+=5-i;
			a[i]--;
		}
	}
	cout<<ans<<endl;
}
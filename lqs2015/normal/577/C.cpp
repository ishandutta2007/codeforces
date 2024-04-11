#include<iostream>
#include<cmath>
using namespace std;
int n,s,ans[111111],k;
bool isprime(int n)
{
	for (int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		if (isprime(i))
		{
			k=i;
			while(k<=n)
			{
				ans[s++]=k;
				k*=i;
			}
		}
	}
	cout<<s<<endl;
	for (int i=0;i<s;i++)
	{
		cout<<ans[i];
		if (i!=s-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}
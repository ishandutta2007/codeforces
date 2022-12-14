#include<iostream>
using namespace std;
long long n,a[1111][1111],ans,sum,psum,pos;
bool f;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if (n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		sum=0;
		f=0;
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==0) 
			{
				pos=j;
				f=1;
			}
			else sum+=a[i][j];
		}
		if (i==1 && f)
		{
			psum=0;
			for (int j=1;j<=n;j++) psum+=a[2][j];
			ans=psum-sum;
			if (ans<=0) 
			{
				cout<<-1<<endl;
				return 0;
			}
			a[i][pos]=ans;
		}
		else if (i==1) psum=sum;
		else if (f)
		{
			ans=psum-sum;
			if (ans<=0)
			{
				cout<<-1<<endl;
				return 0;
			}
			a[i][pos]=ans;
		}
		else if (sum!=psum)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int j=1;j<=n;j++)
	{
		sum=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i][j];
		}
		if (sum!=psum) 
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	sum=0;
	for (int i=1;i<=n;i++) sum+=a[i][i];
	if (sum!=psum) 
	{
		cout<<-1<<endl;
		return 0;
	}
	sum=0;
	for (int i=n;i>=1;i--) sum+=a[i][n+1-i];
	if (sum!=psum)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
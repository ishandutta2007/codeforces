#include<iostream>
using namespace std;
int n;
int a[111][111],b[111][111],mx,s;
char c;
void Set()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		b[i][j]=a[i][j];
	}
}
void rush(int j)
{
	for (int i=1;i<=n;i++)
	{
		b[i][j]=1-b[i][j];
	}
}
int check()
{
	bool f=0;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		f=0;
		for (int j=1;j<=n;j++)
		{
			if (b[i][j]==0) f=1;
		}
		if (!f) res++;
	}
	return res;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>c;
			a[i][j]=(int)c-48;
		}
	}
	for (int i=1;i<=n;i++)
	{
		Set();
		for (int j=1;j<=n;j++)
		{
			if (b[i][j]==0)
			{
				rush(j);
			}
		}
		s=check();
		if (s>mx) mx=s;
	}
	cout<<mx<<endl;
	return 0;
}
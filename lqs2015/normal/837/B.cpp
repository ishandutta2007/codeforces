#include<iostream>
#include<string>
using namespace std;
int n,m;
bool f;
string s[111];
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	if (n%3 && m%3) 
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if (n%3==0)
	{
		for (int i=0;i<n/3;i++)
		{
			for (int j=0;j<m;j++) 
			{
				if (s[i][j]!=s[0][0]) f=1;
			}
		}
		for (int i=n/3;i<2*n/3;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]!=s[n/3][0]) f=1;
			}
		}
		for (int i=2*n/3;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (s[i][j]!=s[2*n/3][0]) f=1;
			}
		}
		if (!f && s[0][0]!=s[n/3][0] && s[0][0]!=s[2*n/3][0] && s[n/3][0]!=s[2*n/3][0])
		{
			cout<<"YES"<<endl;
			return 0;
		} 
	}
	f=0;
	if (m%3==0)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m/3;j++) 
			{
				if (s[i][j]!=s[0][0]) f=1;
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=m/3;j<2*m/3;j++)
			{
				if (s[i][j]!=s[0][m/3]) f=1;
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=2*m/3;j<m;j++)
			{
				if (s[i][j]!=s[0][2*m/3]) f=1;
			}
		}
		if (!f && s[0][0]!=s[0][m/3] && s[0][0]!=s[0][2*m/3] && s[0][m/3]!=s[0][2*m/3])
		{
			cout<<"YES"<<endl;
			return 0;
		} 
	}
	cout<<"NO"<<endl;
	return 0;
}
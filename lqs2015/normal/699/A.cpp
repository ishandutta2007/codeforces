#include<iostream>
using namespace std;
int n,a[222222],mn;
char s[222222];
const int Inf=2000000000;
int main()
{
	mn=Inf;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n-1;i++)
	{
		if (s[i]=='R')
		{
			if (s[i+1]=='L') mn=min(mn,(a[i+1]-a[i])/2);
		}
	}
	if (mn==Inf) cout<<"-1"<<endl;
	else cout<<mn<<endl;
	return 0;
}
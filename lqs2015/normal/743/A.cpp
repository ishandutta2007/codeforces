#include<iostream>
using namespace std;
bool a[111111];
int n,s,e,mn;
char c;
int main()
{
	cin>>n>>s>>e;
	for (int i=1;i<=n;i++)
	{
		cin>>c;
		a[i]=c-'0';
	}
	if (a[s]==a[e]) 
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
 }
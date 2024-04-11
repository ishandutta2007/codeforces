#include<bits/stdc++.h>
using namespace std;
void dfs()
{
	int t,a[30001],c0=0,c1=0,c2=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=t;i++)
	{
		if(a[i]%3==0) c0++;
		if(a[i]%3==1) c1++;
		if(a[i]%3==2) c2++;
	}
	int ans=0;
	t=t/3;
	while(c0!=c1||c1!=c2)
	{
		for(;c0<t;c0++) 
		{
			c2--;
			ans++;
		}
		for(;c1<t;c1++) 
		{
			c0--;
			ans++;
		}
		for(;c2<t;c2++) 
		{
			c1--;
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		dfs();
}
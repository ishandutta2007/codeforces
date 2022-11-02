#include<bits/stdc++.h>
using namespace std;
void tf()
{
	int n,a[101];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt = 0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]!=a[i]) cnt++;
		}
		if(cnt>1) 
		{
			cout<<i<<endl;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		tf();
}
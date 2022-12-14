#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[n+1]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		if(n%2==0)
		{
			for(int i=1;i<=n/2;i++)
			{
				cout<<a[i]<<' '<<a[n-i+1]<<' ';
			}
		}else{
			for(int i=1;i<=n/2;i++)
			{
				cout<<a[i]<<' '<<a[n-i+1]<<' ';
			}
			cout<<a[n/2+1];
		}
		cout<<endl;
	}
}
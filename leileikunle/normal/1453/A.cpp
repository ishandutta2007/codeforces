#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int m,n; cin>>m>>n;
		int a[m]; int b[n];
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		int sum = 0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i]==b[j]) sum++;
			}
		}
		cout<<sum<<endl; 
	}
}
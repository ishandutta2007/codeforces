#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		char a[201];
		cin>>a;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='t')
			{
				for(int j=n-1;j>=i;j--)
				{
					if(a[j]!='t')
					{
						swap(a[i],a[j]);
					}
				}
			}
		}
		cout<<a<<endl;
	}
 }
#include <bits/stdc++.h>

using namespace std;

string s;
int a[105], b[105];
	int ans[10005];
signed main()
{
    int n;
    cin>>n;
    cin>>s;
    s='!'+s;
    for(int i=1; i<=n; i++)
    {
    	cin>>a[i]>>b[i];
	}
	for(int i=1; i<=n; i++)
	{
		int state=s[i]-'0';
		for(int j=0; j<=10000; j++)
		{
			if(j>=b[i])
			{
				if(j%a[i]==(b[i]%a[i]))
				{
					state=1-state;
				}
			}
			ans[j]+=state;
		}
	}
	int anss=0;
	for(int i=0; i<=10000; i++)
	{
		anss=max(anss, ans[i]);
	}
	cout<<anss;
}
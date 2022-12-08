#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
bool yes[100005];
bool d[1482901];
int sum=0;
signed main()
{
	cin>>n;
	int sum=0;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]>0) d[i]=true;
		if(a[i]%2!=0)
		{
			yes[i]=true;
		}
		a[i]/=2;
		sum+=a[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(sum>0&&!d[i]&&yes[i])
		{
			sum--;
			a[i]--;
		}
		if(sum<0&&d[i]&&yes[i])
		{
			sum++;
			a[i]++;
		}
		cout<<a[i]<<endl;
	}
}
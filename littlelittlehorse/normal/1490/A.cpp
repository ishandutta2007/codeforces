#include<bits/stdc++.h>
using namespace std;
void dfs()
{
	int t,a[101];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=t-1;i++)
	{
		int x = a[i], y = a[i + 1];
		if (x > y)
			swap(x, y);
		for (; x * 2 < y; x *= 2)
			++ans;
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
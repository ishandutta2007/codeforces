#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[200005], slol=0;
int lol[200005];
map<int, int> ok[200005];
int sm=0;

void sub(int pos)
{
	lol[pos]--;
	if(lol[pos]<a[pos])
	{
		slol--;
	}
}

void add(int pos)
{
	lol[pos]++;
	if(lol[pos]<=a[pos])
	{
		slol++;
	}	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		sm+=a[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		int u, v, k;
		cin>>u>>v>>k;
		if(ok[u][v]!=0)
		{
			sub(ok[u][v]);
			if(k)
			{
				ok[u][v]=k;
				add(k);
			}
			else
			{
				ok[u][v]=0;
			}
		}
		else
		{
			if(k)
			{
				ok[u][v]=k;
				add(k);
			}
		}
		cout<<sm-slol<<'\n';
	}
}
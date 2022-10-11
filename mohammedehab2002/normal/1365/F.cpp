#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a[505],b[505],l[505],r[505];
vector<int> v[505];
bool vis[505];
bool match(int i)
{
	if (vis[i])
	return 0;
	vis[i]=1;
	for (int u:v[i])
	{
		if (l[u]==-1)
		{
			l[u]=i;
			r[i]=u;
			return 1;
		}
	}
	for (int u:v[i])
	{
		if (match(l[u]))
		{
			l[u]=i;
			r[i]=u;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		v[i].clear();
		for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for (int i=0;i<n;i++)
		scanf("%d",&b[i]);
		for (int i=0;i<n/2;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (a[i]==b[j] && a[n-i-1]==b[n-j-1])
				v[i].push_back(min(j,n-j-1));
			}
			shuffle(v[i].begin(),v[i].end(),rng);
		}
		memset(l,-1,sizeof(l));
		memset(r,-1,sizeof(r));
		int ok=1;
		while (ok--)
		{
			memset(vis,0,sizeof(vis));
			for (int i=0;i<n/2;i++)
			ok|=(r[i]==-1 && match(i));
		}
		bool y=1;
		for (int i=0;i<n/2;i++)
		y&=(r[i]!=-1);
		if (n%2)
		y&=(a[n/2]==b[n/2]);
		puts(y? "Yes":"No");
	}
}
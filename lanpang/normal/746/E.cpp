#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , a[maxn] , s[2];
set<int> st[2] , c;

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		st[a[i]%2].insert(a[i]);
	}
	while (st[0].size() > n/2) st[0].erase(st[0].begin());
	while (st[1].size() > n/2) st[1].erase(st[1].begin());
	s[0] = st[0].size();
	s[1] = st[1].size();
	for (i = 1 ; i <= m ; i++)
	{
		if (s[0] == n/2 && s[1] == n/2) break;
		if (s[i%2] < n/2 && st[i%2].find(i) == st[i%2].end()) 
		{
			s[i%2]++;
			c.insert(i);
		}
	}
	if (s[0] < n/2 || s[1] < n/2)
	{
		cout << "-1\n";
		return 0;
	}
	cout << c.size() << "\n";
	for (i = 1 ; i <= n ; i++)
	{
		if (st[a[i]%2].find(a[i]) == st[a[i]%2].end())
		{
			a[i] = *c.begin();
			c.erase(c.begin());
		}
		else st[a[i]%2].erase(st[a[i]%2].find(a[i]));
		printf("%d ",a[i]);
	}
	return 0;
}
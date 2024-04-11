#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

struct mmp{
	int x , y;
	bool operator < (const mmp &op) const{
		return x < op.x;
	}
}p;
vector<mmp> v[2];
int n , m , a[maxn] , tp , si;

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d",&j,&p.x,&p.y);
		v[j].push_back(p);
	}
	sort(v[1].begin(),v[1].end());
	si = n+1;
	for (auto p: v[1])
	{
		for (; tp < p.x ;)
			a[++tp] = --si;
		for (; tp < p.y ;)
			a[++tp] = si;
	}
	for (; tp < n ;)
		a[++tp] = --si;
	for (auto p: v[0])
	{
		if (a[p.x] == a[p.y])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (i = 1 ; i <= n ; i++)
		printf("%d ",a[i]);
	cout << "\n";
	return 0;
}
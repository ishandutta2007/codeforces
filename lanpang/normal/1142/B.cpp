#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , q , a[maxn] , b[maxn] , c[maxn] , aa[maxn] , la[maxn] , st[maxn] , tp;
vector<int> v[maxn];

void dfs(int x)
{
	st[++tp] = x;
	if (tp > n) c[x] = st[tp-n+1];
	for (auto to: v[x])
		dfs(to); 
	tp--;
}

int main()
{
	int i , j , x , y;
	cin >> n >> m >> q;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (i >= 2) aa[a[i]] = a[i-1];
	}
	aa[a[1]] = a[n];
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d",&b[i]);
		v[la[aa[b[i]]]].push_back(i);
		la[b[i]] = i;
	}
	dfs(0);
	for (i = 1 ; i <= m ; i++)
		c[i] = max(c[i],c[i-1]);
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%c",(c[y] >= x ? '1' : '0'));
	}
	cout << "\n";
	return 0;
}
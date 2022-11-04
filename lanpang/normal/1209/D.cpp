#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , f[maxn] , s;

int getf(int x)
{
	if (f[x] != x) f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	int i , j , x , y;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		f[i] = i;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		x = getf(x);
		y = getf(y);
		if (x != y) f[x] = y;
	}
	s = n;
	for (i = 1 ; i <= n ; i++)
		if (getf(i) == i) s--;
	cout << m-s << "\n";
	return 0;
}
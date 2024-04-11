#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, n) for(int i = 0; i < n; i ++)
using namespace std;

int a[200010][30];
int main()
{
	int T;
	cin >> T;
	rep(i, 1, 200000)
		rep(j, 0, 30)
			a[i][j] = !(i >> j & 1);
	// rep(i, 1, 10)
	// {
	// 	rep(j, 1, 5)
	// 		cout << a[i][j] << " ";
	// 	puts("");	
	// }
	rep(j, 1, 30)
		rep(i, 1, 200000)
			a[i][j] += a[i - 1][j];
	// rep(i, 1, 10)
	// {
	// 	rep(j, 0, 5)
	// 		cout << a[i][j] << " ";
	// 	puts("");	
	// }
	while(T --)
	{
		int l, r;
		cin >> l >> r;
		int x = 200000;
		rep(j, 0, 30)
			x = min(a[r][j] - a[l - 1][j], x);
		cout << x << "\n";
	}

	return 0;
}
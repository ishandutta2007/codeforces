#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int mod = 998244353;
const int N = 1010;
int a[N], b[N];
int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int x, n, m;
		scanf("%d %d %d", &x, &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, m) scanf("%d", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		if(a[n] > b[m]) puts("YES");
		else puts("NO");
	}

	return 0;
}
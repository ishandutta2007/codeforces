#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, a[N][N], cnt[N][N], ans[N], out[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = read(), ++cnt[a[i][j]][i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (cnt[i][j] > cnt[i][ans[i]])
				ans[i] = j;
	for (int i = 1; i <= n; ++i)
		out[ans[i]] = i;
	for (int i = 1; i <= n; ++i)
		printf("%d ", out[i] ? out[i] : n);
	return 0;
}
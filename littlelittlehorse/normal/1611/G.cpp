#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, test, f[1000001];
string str[1000001];

int calc(int x, int y) {
	return (x - 1) * m + y - 1;
}

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			cin >> str[i];
		if (n == 1) {
			int ans = 0;
			for (int j = 0; j < m; j++)
				if (str[1][j] == '1')
					++ans;
			printf("%d\n", ans);
			continue;
		}
		for (int i = 0; i <= n * m; i++)
			f[i] = 0;
		for (int j = 1; j <= m; j++) 
			for (int i = 1; i <= n; i++){
				f[calc(i, j)] = (str[i][j - 1] == '1');
				if (j > 2)
					f[calc(i, j)] += f[calc(i, j - 2)];
				if (i > 1 && j > 1)
				f[calc(i, j)] = max(f[calc(i, j)], f[calc(i - 1, j - 1)]);
				if (i != n && j > 1)
					f[calc(i, j)] = max(f[calc(i, j)], f[calc(i + 1, j - 1)]);
			}
		int ans0 = 0, ans1 = 0;
		for (int i = 1; i <= n; i++)
			if ((i + m) & 1)
				ans1 = max(ans1, f[calc(i, m)]);
			else 
				ans0 = max(ans0, f[calc(i, m)]);
		printf("%d\n", ans0 + ans1);
	}
}
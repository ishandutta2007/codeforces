#include <bits/stdc++.h>

using namespace std;

const int N = 103;

int n, k, t[N][N], cnt;
char p[N][N];
priority_queue<pair<int, pair<int,int>>> Q;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%s", p[i] + 1);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 12; ++j) {
			if (p[i][j] == 'S')
				t[i][j] = 1;
			if (p[i][j] == '.')
				t[i][j] = 0;
			if (p[i][j] == 'P')
				t[i][j] = 3;
			if (p[i][j] == '-')
				t[i][j] = -1;
		}
	}

	int res = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 12; ++j) {
			if (t[i][j] == 3 || t[i][j] == 1) {
				if (t[i][j - 1] == 1)
					++res;
				if (t[i][j + 1] == 1)
					++res;
			}
			if (t[i][j] == 0) {
				cnt = 0;
				if (t[i][j - 1] == 1)
					++cnt;
				if (t[i][j + 1] == 1)
					++cnt;
				Q.push({-cnt, {i, j}});
			}
		}
	}

	for (int i = 1; i <= k; ++i) {
		auto x = Q.top();Q.pop();
		res += -x.first;
		p[x.second.first][x.second.second] = 'x';
	}

	printf("%d\n", res);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 12; ++j) 
			printf("%c", p[i][j]);
		printf("\n");
	}
}
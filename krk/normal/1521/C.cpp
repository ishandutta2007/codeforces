#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;

int Ask(int t, int i, int j, int x)
{
	printf("? %d %d %d %d\n", t, i, j, x); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int one = n;
		for (int i = 1; i + 1 <= n; i += 2) {
			int got = Ask(2, i, i + 1, 1);
			if (got == 1) { one = i; break; }
			if (got == 2) {
				got = Ask(2, i + 1, i, 1);
				if (got == 1) { one = i + 1; break; }
			}
		}
		vector <int> res;
		for (int i = 1; i <= n; i++)
			if (i == one) res.push_back(1);
			else res.push_back(Ask(1, one, i, n - 1));
		printf("!");
		for (int i = 0; i < res.size(); i++)
			printf(" %d", res[i]);
		printf("\n"); fflush(stdout);
	}
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, x1, x2;
ii seq[Maxn];

int main()
{
	scanf("%d %d %d", &n, &x1, &x2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i].first);
		seq[i].second = i + 1;
	}
	sort(seq, seq + n);
	for (int i = 0; i < n; i++) {
		int k = (x1 + seq[i].first - 1) / seq[i].first;
		if (i + k < n) {
			int ni = i + k;
			int nk = (x2 + seq[ni].first - 1) / seq[ni].first;
			if (ni + nk <= n) {
				printf("Yes\n");
				printf("%d %d\n", k, nk);
				for (int j = i; j < i + k; j++)
					printf("%d%c", seq[j].second, j + 1 < i + k? ' ': '\n');
				for (int j = ni; j < ni + nk; j++)
					printf("%d%c", seq[j].second, j + 1 < ni + nk? ' ': '\n');
				return 0;
			}
		}
		k = (x2 + seq[i].first - 1) / seq[i].first;
		if (i + k < n) {
			int ni = i + k;
			int nk = (x1 + seq[ni].first - 1) / seq[ni].first;
			if (ni + nk <= n) {
				printf("Yes\n");
				printf("%d %d\n", nk, k);
				for (int j = ni; j < ni + nk; j++)
					printf("%d%c", seq[j].second, j + 1 < ni + nk? ' ': '\n');
				for (int j = i; j < i + k; j++)
					printf("%d%c", seq[j].second, j + 1 < i + k? ' ': '\n');
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
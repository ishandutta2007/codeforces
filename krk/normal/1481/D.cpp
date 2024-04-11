#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", B[i] + 1);
		int a = -1, b = -1, c = -1;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (B[i][j] == B[j][i]) { a = i; b = j; }
		if (a != -1) {
			printf("YES\n");
			for (int i = 0; i < m + 1; i++) {
				printf("%d%c", a, i + 1 < m + 1? ' ': '\n');
				swap(a, b);
			}
			continue;
		}
		if (m % 2 == 1) {
			int a = 1, b = 2;
			printf("YES\n");
			for (int i = 0; i < m + 1; i++) {
				printf("%d%c", a, i + 1 < m + 1? ' ': '\n');
				swap(a, b);
			}
			continue;
		}
		a = -1, b = -1, c = -1;
		for (int i = 1; i <= n; i++) {
			int fromA = -1, toA = -1;
			int fromB = -1, toB = -1;
			for (int j = 1; j <= n; j++) if (i != j) {
				if (B[j][i] == 'a') fromA = j;
				else fromB = j;
				if (B[i][j] == 'a') toA = j;
				else toB = j;
			}
			if (fromA != -1 && toA != -1) {
				a = fromA; b = i; c = toA;
				break;
			}
			if (fromB != -1 && toB != -1) {
				a = fromB; b = i; c = toB;
				break;
			}
		}
		if (a != -1) {
			printf("YES\n");
			vector <int> seq;
			int u = b, v = a;
			for (int i = 0; i < m / 2 + 1; i++) {
				seq.push_back(u);
				swap(u, v);
			}
			for (int i = int(seq.size()) - 1; i >= 0; i--)
				printf("%d ", seq[i]);
			u = c, v = b;
			for (int i = 0; i < m / 2; i++) {
				printf("%d%c", u, i + 1 < m / 2? ' ': '\n');
				swap(u, v);
			}
			continue;
		}
		printf("NO\n");
	}
    return 0;
}
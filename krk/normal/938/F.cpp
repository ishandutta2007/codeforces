#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Maxm = 12;

int n, k;
char str[Maxn];
vector <int> neigh[1 << Maxm];
char best[Maxn][1 << Maxm];
bool vis[Maxn][1 << Maxm];

int main()
{
	scanf("%s", str); n = strlen(str);
	if (n == 1) { printf("%s\n", str); return 0; }
	int num = n;
	while (num > 1) { num /= 2; k++; }
	for (int i = 0; i < 1 << k; i++)
		for (int j = 0; j < k; j++)
			if (!(i & 1 << j)) neigh[i].push_back(j);
	int lft = n - ((1 << k) - 1);
	for (int i = lft - 1; i >= 0; i--)
		for (int j = (1 << k) - 1; j >= 0; j--) {
			best[i][j] = str[i + j];
			for (int l = 0; l < neigh[j].size(); l++)
				best[i][j] = min(best[i][j], best[i][j | 1 << neigh[j][l]]);
		}
	vis[0][0] = true;
	for (int i = 0; i < lft; i++) {
		char my = 'z';
		for (int j = 0; j < 1 << k; j++) if (vis[i][j])
			my = min(my, best[i][j]);
		printf("%c", my);
		for (int j = 0; j < 1 << k; j++) if (vis[i][j] && best[i][j] == my) {
			if (str[i + j] == my) vis[i + 1][j] = true;
			for (int l = 0; l < neigh[j].size(); l++)
				if (best[i][j | 1 << neigh[j][l]] == my) vis[i][j | 1 << neigh[j][l]] = true;
		}
	}
	printf("\n");
	return 0;
}
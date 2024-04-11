#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxm = 100005;

int T;
int n, m;
int A[Maxn][Maxn];
int B[Maxn][Maxn];
char str[Maxm];
ii my[3];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &A[i][j]);
				A[i][j]--;
			}
		scanf("%s", str);
		my[0] = ii(0, 0);
		my[1] = ii(1, 0);
		my[2] = ii(2, 0);
		for (int i = 0; i < m; i++)
			if (str[i] == 'R') my[1].second = (my[1].second + 1) % n;
			else if (str[i] == 'L') my[1].second = (my[1].second - 1 + n) % n;
			else if (str[i] == 'D') my[0].second = (my[0].second + 1) % n;
			else if (str[i] == 'U') my[0].second = (my[0].second - 1 + n) % n;
			else if (str[i] == 'I') swap(my[1], my[2]);
			else if (str[i] == 'C') swap(my[0], my[2]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int got[3] = {i, j, A[i][j]};
				int fir = (got[my[0].first] + my[0].second) % n;
				int sec = (got[my[1].first] + my[1].second) % n;
				int thir = (got[my[2].first] + my[2].second) % n;
				B[fir][sec] = thir;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				B[i][j]++;
				printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
			}
	}
    return 0;
}
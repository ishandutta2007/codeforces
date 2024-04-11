#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 105;

int T;
int n, m;
int B[Maxn][Maxn];
int num[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		vector <iii> seq;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				num[i][j] = -1;
				int b; scanf("%d", &b);
				B[i][j] = b;
				seq.push_back(iii(b, ii(i, j)));
			}
		sort(seq.begin(), seq.end());
		for (int j = 0; j < m; j++)
			num[seq[j].second.first][j] = seq[j].second.second;
		for (int i = 0; i < n; i++) {
			set <int> S;
			for (int j = 0; j < m; j++)
				S.insert(j);
			for (int j = 0; j < m; j++) if (num[i][j] != -1)
				S.erase(num[i][j]);
			for (int j = 0; j < m; j++) if (num[i][j] == -1) {
				num[i][j] = *S.begin();
				S.erase(S.begin());
			}
			for (int j = 0; j < m; j++)
				printf("%d%c", B[i][num[i][j]], j + 1 < m? ' ': '\n');
		}
	}
    return 0;
}
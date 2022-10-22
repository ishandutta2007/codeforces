#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 404;

int T;
int n;
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector <ii> seq;
		for (int i = 0; i < n; i++) {
			scanf("%s", B[i]);
			for (int j = 0; j < n; j++)
				if (B[i][j] == '*')
					seq.push_back(ii(i, j));
		}
		if (seq[0].first == seq[1].first) {
			int row = seq[0].first == 0? 1: 0;
			B[row][seq[0].second] = B[row][seq[1].second] = '*';
		} else if (seq[0].second == seq[1].second) {
			int col = seq[0].second == 0? 1: 0;
			B[seq[0].first][col] = B[seq[1].first][col] = '*';
		} else {
			B[seq[0].first][seq[1].second] = B[seq[1].first][seq[0].second] = '*';
		}
		for (int i = 0; i < n; i++)
			printf("%s\n", B[i]);
	}
    return 0;
}
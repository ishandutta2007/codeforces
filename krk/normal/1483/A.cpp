#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
int cnt[Maxn];
int my[Maxn];
vector <vector <int> > F;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		fill(cnt + 1, cnt + n + 1, 0);
		F.clear();
		for (int i = 0; i < m; i++) {
			vector <int> tmp;
			int k; scanf("%d", &k);
			tmp.resize(k);
			for (int j = 0; j < k; j++)
				scanf("%d", &tmp[j]);
			cnt[tmp[0]]++;
			my[i] = 0;
			F.push_back(tmp);
		}
		int mx = (m + 1) / 2;
		int i = -1;
		for (int j = 1; j <= n; j++)
			if (cnt[j] > mx) i = j;
		if (i != -1) {
			for (int d = 0; d < m && cnt[i] > mx; d++)
				if (F[d][0] == i && F[d].size() > 1) {
					cnt[i]--;
					my[d] = 1;
				}
			if (cnt[i] > mx) { printf("NO\n"); continue; }
		}
		printf("YES\n");
		for (int i = 0; i < m; i++)
			printf("%d%c", F[i][my[i]], i + 1 < m? ' ': '\n');
	}
    return 0;
}
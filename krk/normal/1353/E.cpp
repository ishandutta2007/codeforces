#include <bits/stdc++.h>
using namespace std;

const int Maxm = 1000005;

int T;
int n, k;
char str[Maxm];
vector <int> seq[Maxm];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		scanf("%s", str);
		int all = 0;
		for (int i = 0; i < k; i++)
			seq[i].clear();
		for (int i = 0; i < n; i++)
			if (str[i] == '1') {
				seq[i % k].push_back(i);
				all++;
			}
		int res = all;
		for (int i = 0; i < k; i++) if (!seq[i].empty()) {
			int rem = all - int(seq[i].size());
			int cur = rem;
			res = min(res, all - 1);
			for (int j = 1; j < seq[i].size(); j++) {
				cur += (seq[i][j] - seq[i][j - 1]) / k - 1;
				cur = min(cur, rem + j);
				res = min(res, cur + int(seq[i].size()) - 1 - j);
			}
		}
		printf("%d\n", res);
	}
    return 0;
}
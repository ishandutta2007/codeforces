#include <bits/stdc++.h>
using namespace std;

#define N 210000

int n, m, k, ss[N];
bool ok[N];
char S[N];

void doit() {
	for (int i = 0; i <= k; i++)
		ok[i] = false;
	ok[0] = true;
	for (int i = 0; i < 26; i++)
		for (int j = k; j >= ss[i]; j--)
			ok[j] |= ok[j - ss[i]];
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < 26; i++)
			ss[i] = 0;
		scanf("%s", S);
		for (int i = 0; i < k; i++)
			ss[S[i] - 'A']++;
		doit();
		int ans = 1e9;
		for (int i = n; i <= k - m; i++)
			if (ok[i])
				ans = 0;

		for (int i = 0; i < 26; i++) {
			int tmp = ss[i];
			ss[i] = 0;
			doit();
			ss[i] = tmp;
			for (int j = 0; j <= n; j++)
				if (ok[j] && k - ss[i] - j <= m)
					ans = min(0LL + ans, 1LL * (n - j) * (m - (k - ss[i] - j)));
		}
		printf("%d\n", ans);
	}
}
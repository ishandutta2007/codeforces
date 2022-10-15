#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


char s[int(2e5 + 111)];
int cnt[int(2e5 + 111)][26];
int main() {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1)), Q;
	for (int i = 1; i <= n; i++) {
		for (int j = 'a'; j <= 'z'; j++) {
			cnt[i][j - 'a'] = cnt[i - 1][j - 'a'] + (s[i] == j);
		}
	}
	read(Q);
	while (Q--) {
		int l, r;
		read(l); read(r);
		int k = 0;
		for (int j = 'a'; j <= 'z'; j++) {
			if (cnt[r][j - 'a'] - cnt[l - 1][j - 'a']) k ++;
		}
		if (l == r) puts("Yes");
		else if (k == 1) puts("No");
		else if (k == 2) {
			if (s[l] == s[r]) puts("No");
			else puts("Yes");
		}
		else puts("Yes");
	}
}
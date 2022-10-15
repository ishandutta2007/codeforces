#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N int(1e5 + 7)

int n ;
char s[N];
long long cnt[232333];
int sum[N][26];

int main() {
	scanf("%s", s + 1);
	n = int(strlen(s + 1));
	for (int i = 1; i <= n; i++) {
		cnt[s[i]] ++;
	}
	long long ans = 0;
	for (int i = 'a'; i <= 'z'; i++) ans = max(ans, (LL)cnt[i]), cnt[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x = s[i] - 'a';
		for (int j = 0; j < 26; j++) {
			sum[i][j] = sum[i - 1][j] + (x == j);
		}
	}
	for (int i = n; i >= 1; i--) {
		int x = s[i] - 'a';
		for (int j = 0; j < 26; j++) {
			cnt[(x + 1) * 27 + j] += sum[i - 1][j];
		}
	}
	for (int x = 0; x < 26; x++) {
		for (int j = 0; j < 26; j++) {
			ans = max(ans, cnt[(x + 1) * 27 + j]);
		}
	}
	cout << ans << endl;
}
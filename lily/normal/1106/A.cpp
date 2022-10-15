#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

int n;
char s[1005][1005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
	}
	int ans = 0;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++) {
			if (s[i][j] == 'X' &&
				s[i + 1][j - 1] == 'X' &&
				s[i + 1][j + 1] == 'X' &&
				s[i - 1][j - 1] == 'X' &&
				s[i - 1][j + 1] == 'X')
				ans++;

		}
	cout << ans << endl;


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N 1011111

int n;
char s[N];

int main() {
	read(n);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += s[i] == '(' ? 1 : -1;
	}
	if (cnt != 0) return puts("-1"), 0;
	cnt = 0;
	int L = -1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cnt += s[i] == '(' ? 1 : -1;
		if (cnt < 0 && L == -1) {
			L = i;
		}
		else if (s[i] == '(' && cnt == 0) {
			ans += i - L + 1;
			L = -1;
		}
	}
	cout << ans << endl;
}
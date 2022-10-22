#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int n, m;
char s[N], t[N];
int a[N], b[N];
int main() {
	cin >> n >> m;
	cin >> (s + 1) >> (t + 1);
	int now = 1;
	for(int i = 1; i <= n && now <= m; i++) {
		if(s[i] == t[now]) {
			a[now] = i;
			now++;
		}
	}
	now = m;
	for(int i = n; i >= 1 && now > 0; i--) {
		if(s[i] == t[now]) {
			b[now] = i;
			now--;
		}
	}
	int ans = 0;
	for(int i = 1; i < m; i++) {
		if(a[i] < b[i + 1]) {
			ans = max(b[i + 1] - a[i], ans);
		}
	}
	cout << ans << endl;
    return 0;
}
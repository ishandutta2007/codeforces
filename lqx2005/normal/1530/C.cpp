#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int T, a[N], b[N];
void work() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	reverse(a + 1, a + n + 1), reverse(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	} 
	int cnt = 0;
	for(;; cnt++) {
		int now = (n + cnt) - (n + cnt) / 4;
		int sa = min(now, cnt) * 100 + a[now - min(now, cnt)];
		int sb = b[min(n, now)];
		if(sa >= sb) {
			break;
		}
	}
	cout << cnt << endl;
	return;
}

int main() {
	cin >> T;
	for(; T--; ) work();
	return 0;
}
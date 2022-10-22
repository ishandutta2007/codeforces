#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
int n, k;
int cnt[N], L[N], cur = 0, used[N];
int ansl[N], ansr[N];
void solve() {
	cin >> n >> k;
	for(int i = 1, x; i <= n * k; i++) {
		cin >> x;
		if(used[x]) continue;
		if(cnt[x] == 0) {
			cnt[x]++, L[x] = i;
		} else {
			ansl[x] = L[x], ansr[x] = i;
			cnt[x] = 0, cur++, used[x] = 1;
		}
		if(cur >= (n + k - 2) / (k - 1)) {
			cur = 0;
			for(int i = 1; i <= n; i++) {
				L[i] = cnt[i] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << ansl[i] <<" " << ansr[i] << endl;
	return;
}

int main() {
	solve();
    return 0;
}
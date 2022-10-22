#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
const int N = 300 + 10;;
int T, n, m;
int a[N * N], id[N * N];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		id[i] = i;
	}
	sort(id + 1, id + m + 1, [&](int x, int y) {
		if(a[x] != a[y]) return a[x] < a[y];
		return x > y;
	});
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = i + 1; j <= m; j++) {
			if(id[i] < id[j]) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return;
}

int main() {
	cin >> T;
	for(; T--; ) {
		solve();
	}
	return 0;
}
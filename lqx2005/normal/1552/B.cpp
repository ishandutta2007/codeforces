#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, a[N][5];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int pos = 1;
	for(int i = 2; i <= n; i++) {
		int cnt = 0;
		for(int j = 0; j < 5; j++) {
			if(a[i][j] < a[pos][j]) {
				cnt++;
			}
		}
		if(cnt >= 3) {
			pos = i;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(i == pos) continue;
		int cnt = 0;
		for(int j = 0; j < 5; j++) {
			if(a[i][j] < a[pos][j]) {
				cnt++;
			}
		}
		if(cnt >= 3) {
			cout << -1 << endl;
			return;
		}
	}
	cout << pos << endl;
	return;
}

int main() {
	int T;
	for(cin >> T;T-- ; ) {
		solve();
	}
    return 0;
}
#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 3e7 + 10;
int cnt[N], a[N];
void solve() {
	int n, m;
	cin >> n >> m;
	int p = m;
	int tot = 0;
	for(int i = 1; tot < n; i++) {
		if(m < cnt[i]) {
			break;
		}
		m -= cnt[i];
		a[++tot] = i;
		for(int j = 1; j < i; j++) cnt[a[j] + a[tot]]++;
	}
	for(int i = a[tot] + 1; tot < n; i++) {
		if(m >= cnt[i]) {
			a[++tot] = i;
			m -= cnt[i];
			for(int j = 1; j < tot; j++) cnt[a[j] + a[tot]]++;
		}
	}
	if(m) {
		cout << -1 << endl;
		return;
	}
	// for(int i = 1; i <= tot; i++) {
	// 	for(int j = i + 1; j <= tot; j++) {
	// 		for(int k = j + 1; k <= tot; k++) {
	// 			if(a[i] + a[j] == a[k]) {
	// 				p--;
	// 			}
	// 		}
	// 	}
	// }
	// assert(p == 0);
	for(int i = 1; i <= n; i++) cout << a[i] <<" ";
	cout << endl;
	return;
}

int main() {
	solve();
	return 0;
}
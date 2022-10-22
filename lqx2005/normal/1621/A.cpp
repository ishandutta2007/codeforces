#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
int n, k;
void solve() {
	cin >> n >> k;
	if((n + 1) / 2 < k) {
		cout << -1 << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				if((i & 1) && k) cout << "R", k--;
				else cout << ".";
			} else cout << ".";
		}
		cout << endl;
	}
	return;
}
int main() {
	int t;
	for(cin >> t; t--; solve());
    return 0;
}
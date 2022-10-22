#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 1e4 + 10;
int n, a[N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = i; j <= n; j++) {
			if(a[j] == 0) cnt++;
			cnt++;
			sum += cnt;
		}
	}
	cout << sum << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}
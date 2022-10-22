#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 1e5 + 10;
int n, a[N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int mx = 0, odd = 0;
	for(int i = 2; i < n; i++) mx = max(mx, a[i]), odd ^= (a[i] & 1);
	if(mx == 1 || (n == 3 && odd)) {
		cout << -1 << endl;
		return;
	}
	ll sum = 0;
	for(int i = 2; i < n; i++) {
		sum += a[i];
		if(a[i] & 1) sum++;
	}
	cout << sum / 2 << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}
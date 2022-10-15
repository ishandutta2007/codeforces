#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout << #x << ": " << x << "\n";
void solve() { 
	// i will write my code here, or i will sleep like sleep.out
	int n;
    cin >> n;
    int l = 1, r = n + 1;
    while (l < r - 1) {
		int mid = (l + r) >> 1, x, y;
		cout << "? " << mid << "\n";
		fflush(stdout);
		cin >> x;
		cout << "? " << mid - 1 << "\n";
		fflush(stdout);
		cin >> y;
		(x < y ? l : r) = mid;
    }
	cout << "! " << l << "\n";
	fflush(stdout);
}
int32_t main() {
    clock_t t1 = clock();
	#ifndef ONLINE_JUDGE
       freopen("wake.in", "r", stdin);
       freopen("sleep.out", "w", stdout);
    #endif 
	// int T;cin >> T;while (T--)
	solve();
    // cout << "Time used: " << clock() - t1 << " ms\n";
	return 0;
}
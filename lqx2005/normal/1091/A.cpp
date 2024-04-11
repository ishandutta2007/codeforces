#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

void solve() {
    int y, b, r;
    cin >> y >> b >> r;
    int cnt = min(min(y, b - 1), r - 2);
    cout << cnt * 3 + 3 << endl;
    return;
}
int main() {
    solve();
    // int t;
    // for(cin >> t; t--; solve());
	return 0;
}
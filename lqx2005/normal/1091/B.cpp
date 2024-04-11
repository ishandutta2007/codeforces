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
const int N = 1e3 + 10;
pair<int, int> a[N], b[N];
void solve() {
    int n;
    cin >> n;
    ll sx = 0, sy = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        sx += a[i].x, sy += a[i].y;
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i].x >> b[i].y;
        sx += b[i].x, sy += b[i].y;
    }
    sx /= n, sy /= n;
    cout << sx <<" " << sy << endl;
    return;
}
int main() {
    solve();
    // int t;
    // for(cin >> t; t--; solve());
	return 0;
}
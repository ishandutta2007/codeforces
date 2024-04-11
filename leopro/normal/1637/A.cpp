
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}
#define answer(ans) {cout << ans << endl; return;}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> max = a, min = a;
    for (int i = 1; i < n; ++i) max[i] = ::max(max[i], max[i - 1]);
    for (int i = n - 2; i >= 0; --i) min[i] = ::min(min[i], min[i + 1]);
    for (int i = 1; i < n; ++i) {
        if (max[i - 1] > min[i]) answer("YES");
    }
    answer("NO")
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> o, z;
    for (int i = 0; i < n; ++i) (a[i] ? o : z).push_back(i);
    reverse(z.begin(), z.end());
    for (int x = 0; x < n; ++x) if (x == z.size() || x == o.size() || z[x] < o[x]) answer(x)
    assert(false);

}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}
#define answer(ans) {cout << (ans) << '\n'; return;}
void solve() {
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    for (int x : a) if (binary_search(a.begin(), a.end(), x + k)) answer("YES");
    answer("NO")
}
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10;
int n, k;
ll s[N];
void solve() {
    cin >> n >> k;
    FOR(i, 0, n) s[i] = 0;
    FOR(i, n - k + 1, n) cin >> s[i];
    ROF(i, n, n - k + 1) s[i] = s[i] - s[i - 1];
    FOR(i, n - k + 3, n) if(s[i - 1] > s[i]) {
        cout << "No\n";
        return;
    }
    if(k > 1 && s[n - k + 2] * (n - k + 1) < s[n - k + 1]) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}
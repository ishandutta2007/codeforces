#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    string aa, bb;
    cin >> aa >> bb;
    FOR(j, 0, n - 1) a[j] = aa[j] - '0';
    FOR(j, 0, m - 1) b[j] = bb[j] - '0';
    FOR(j, n - m + 1, n - 1) if(a[j] != b[j - (n - m)]) {
        cout << "No\n";
        return;
    }
    ROF(j, n - m, 0) {
        if(a[j] == b[0]) {
            cout << "Yes" << "\n";
            return;
        }
    }
    cout << "No\n";
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}
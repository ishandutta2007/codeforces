#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    if(m < n) {
        cout << "No\n";
        return;
    }
    if(n & 1) {
        cout << "Yes\n";
        FOR(i, 1, n - 1) cout << 1 << " ";
        cout << m - (n - 1) << "\n";
    } else {
        if(m & 1) cout << "No\n";
        else {
            cout << "Yes\n";
            FOR(i, 1, n - 2) cout << 1 << " ";
            int x = m - (n - 2);
            x /= 2;
            cout << x <<" " << x << "\n";
        }
    }
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
}
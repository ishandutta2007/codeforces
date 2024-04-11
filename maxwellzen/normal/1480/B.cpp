#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
const int MxN = 1e5 + 1;
int t, n;
ll ha, hb;
pair<ll,ll> m[MxN];

void solve() {
    cin >> ha >> hb >> n;
    for (int i = 0; i < n; i++) cin >> m[i].F;
    for (int i = 0; i < n; i++) cin >> m[i].S;
    sort(m, m+n);
    bool works = true;
    for (int i = 0; i < n; i++) {
        ll dmg = ((m[i].S-1)/ha + 1)*m[i].F;
        hb -= dmg;
    }
    if (hb > -1 * m[n-1].F) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int suf[nax];

int solve(vector <int> a, vector <int> b, int n, int m) {

    suf[n] = 0;

    for (int i = n - 1 ; i >= 0 ; -- i) {
        suf[i] = suf[i + 1] + (binary_search(b.begin(), b.end(), a[i]));
    }

    for (int i = 0 ; i < n ; ++ i)
        a[i] -= i; /// still sorted
        /**
            after push END - START + 1 = pos(END) + 1
            END - pos(END) = START
            since it's sorted find last position END - pos(END) = start
        */

    int ans = suf[0];
    for (int i = 0 ; i < m ; ++ i) {
        int where = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (where <= 0) continue;
        ans = max(ans, int(lower_bound(b.begin(), b.end(), b[i] + where) - b.begin()) - i + suf[where]);
    }
    return ans;
}

int n, m;


void solve() {
    cin >> n >> m;

    vector <int> a(n);
    vector <int> b(m);

    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    vector <int> foo, bar;
    for (int i : a) if (i < 0) foo.push_back(-i);
    for (int i : b) if (i < 0) bar.push_back(-i);
    reverse(foo.begin(), foo.end());
    reverse(bar.begin(), bar.end());
    int ans = solve(foo, bar, foo.size(), bar.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (!a.empty() && a.back() < 0) a.pop_back();
    while (!b.empty() && b.back() < 0) b.pop_back();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << ans + solve(a, b, a.size(), b.size()) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
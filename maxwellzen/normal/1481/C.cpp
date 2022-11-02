#include <bits/stdc++.h>

using namespace std;
#define pb push_back
int t, n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    map<int, vector<int>> same, change;
    set<int> done;
    int w = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]==b[i]) same[a[i]].pb(i);
        else {change[b[i]].pb(i); w++;}
    }
    for (int i = m-1; i >= 0; i--) {
        int temp = change[c[i]].size();
        if (temp>0) {
            d[i]=change[c[i]][temp-1];
            done.insert(d[i]);
            change[c[i]].erase(change[c[i]].begin()+temp-1);
            w--;
        } else if (same[c[i]].size()>0) {
            d[i] = same[c[i]][0];
            done.insert(d[i]);
        } else if (done.size()>0) {
            d[i] = *done.begin();
        } else {
            cout << "NO\n";
            return;
        }
    }
    if (w>0) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < m; i++) cout << d[i]+1 << ' ';
        cout << '\n';
    }
    return;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}
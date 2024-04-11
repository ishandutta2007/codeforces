#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
pair <int, int> ord[nax];
int ct[nax];

void solve() {
    cin >> n;

    vector <int> bar(n);

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        bar[i - 1] = a[i];
    }
    sort(bar.begin(), bar.end());
    bar.erase(unique(bar.begin(), bar.end()), bar.end());

    fill(ct, ct + 1 + n, 0);

    for (int i = 1 ; i <= n ; ++ i) {
        a[i] = lower_bound(bar.begin(), bar.end(), a[i]) - bar.begin();
        ct[a[i]] += 1;
    }
    int b = min_element(ct, ct + bar.size()) - ct;
    vector <int> all_b;
    vector <int> other;

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == b) {
            all_b.push_back(i);
        } else other.push_back(i);
    }
    vector <pair <int, int>> ans;

    for (int to : other)
        ans.emplace_back(all_b[0], to);
    int cur = 0;
    for (int i = 1 ; i < all_b.size() ; ++ i) {
        if (cur >= other.size()) {
            cout << "NO\n";
            return ;
        }
        ans.emplace_back(all_b[i], other[cur]);
    }

    cout << "YES\n";
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ;T -- ;) {
        solve();
    }
}
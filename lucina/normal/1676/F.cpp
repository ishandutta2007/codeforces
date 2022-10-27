#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;

int n, k;
int a[nax];


void solve() {
    cin >> n >> k;
    map <int, int> cnt;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    vector <pair < int, int>> c;

    for (auto &[i, j] : cnt) {
        c.emplace_back(i, j);
    }
    int ans = -1;
    int l, r;

    for (int i = 0 ; i < c.size() ; ++ i) {
        if (c[i].second < k) continue;
        int j = i;
        int bar = 0;
        while (j < c.size() && c[j].second >= k) {
            int dif = c[j].first - c[i].first;
            j += 1;
            if (dif != j - i - 1) {
                j -= 1;
                break;
            };
            if (dif == j - i - 1 && c[j - 1].first - c[i].first > ans) {
                ans = c[j - 1].first - c[i].first;
                l = c[i].first;
                r = c[j - 1].first;
            }
        }
        i = j - 1;
    }
    if (ans == -1) {
        cout << "-1\n";
    } else cout << l << ' ' << r << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}
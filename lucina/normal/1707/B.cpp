#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;

int n;
int a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n;  ++ i) {
        cin >> a[i];
    }
    /**
        the summation of segment is a[n] - a[1]
        with (n - 1) segments
        , there are at most O(sqrt(distinct)) values

    */
    vector <int> b;

    for (int i = 1 ; i < n ; ++ i) {
        b.push_back(a[i + 1] - a[i]);
    }
    sort(b.begin(), b.end());
    /// b.erase(unique(b.begin(), b.end()));
    vector <pair <int, int>> c;

    for (int i = 0 ; i < b.size() ;) {
        int j = i;
        while (j < b.size() && b[j] == b[i]) j += 1;
        c.emplace_back(b[i], j - i);
        i = j;
    }

    while (c.size()) {
        map <int, int> f;
        if (c.size() == 1) {
            if (c[0].second == 1) {
                cout << c[0].first << '\n';
            } else cout << 0 << '\n';
            break;
        }
      //  if (c.size() == 2 && c[0].first == 0) {
       //     cout << c[1].first << '\n';
        //    break;
        //}
        for (int i = 0 ; i < c.size() ; ++ i) {
 //           cout << c[i].first << ' ' << c[i].second << '\n';
            if (i > 0) {
                f[c[i].first - c[i - 1].first] += 1;
            }
            if (c[i].second - 1 > 0) f[0] += c[i].second - 1;

        }
        c.clear();
        for (auto &[u, v] : f) {
            c.emplace_back(u, v);
        }

    }

}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    long time no, div.1
*/
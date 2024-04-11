#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
/**
10
4 2 1 2 2 2 3 3 5 6
*/

void solve() {
    cin >> n;
    int rsum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int sum = accumulate(a + 1, a + 1 + n, 0);
    if (sum % n) {
        cout << "-1\n";
        return;
    }
    int tar = sum / n;
    vector <tuple <int, int, int>> ans;


    vector <pair <int, int>> ord;

    for (int i = 2 ; i <= n ;  ++ i) {
        int dist = i - a[i] % i;
        if (dist == i) dist = 0;
        ord.emplace_back(dist, i);
    }
    sort(ord.begin(), ord.end());

    for (auto [f, i] : ord) {

        ans.emplace_back(1, i, f);
        a[1] -= f;
        a[i] += f;
        a[1] += a[i];
        ans.emplace_back(i, 1, a[i] / i);
    }

    for (int i = 2 ; i <= n ; ++ i) {
        ans.emplace_back(1, i, tar);
    }


    vector <tuple <int, int, int>> real;

    for (auto [u, v, w] : ans) {
        if (w == 0) continue;
        real.emplace_back(u, v, w);
    }

    ans.swap(real);
    cout << ans.size() << '\n';
    for (auto [u, v, w] : ans) {
        cout << u << ' ' << v << ' ' << w << '\n';
    }

}

int main() {
    //cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/
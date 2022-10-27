#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
using ll = int64_t;
int n, k;
ll m;

vector <pair <ll, ll>> t(vector <ll> a) {
    vector <pair <ll, ll>> b;
    for (ll x : a) {
        ll f = 1;
        while (x % m == 0) {
            f *= m;
            x /= m;
        }
        b.push_back({x, f});
    }

    vector <pair <ll, ll>> c;

    for (int i = 0 ; i < b.size() ;) {
        int j = i;
        ll sum = 0;
        while (j < b.size() && b[i].first == b[j].first) {
            sum += b[j].second;
            j += 1;
        }
        c.push_back({b[i].first, sum});
        i = j;
    }
//    for (auto &[x, y] : c) {
//        cout << x << ' ' << y << '\n';
//    }
//    cout << "____\n";
    return c;
}

bool solve() {
    cin >> n >> m;
    vector <ll> a(n);

    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    cin >> k;
    vector <ll> b(k);
    for (int i = 0 ; i < k ; ++ i) {
        cin >> b[i];
    }
    return t(a) == t(b);
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/**
    ....Global round....
*/
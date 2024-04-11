#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int largest_bit(int x) {
    for (int j = 60; j >= 0; j--) {
        if ((1ll << j) & x)
            return j;
    }
}

vector<int> slow(int n) {
    unordered_set<int> used;
    vector<int> s;
    for (int x = 1; (int) s.size() < n;) {
        while (used.count(x))
            x++;
        used.insert(x);
        s.push_back(x);
        int y = x + 1;
        while (used.count(y) || used.count(x ^ y))
            y++;
        s.push_back(y);
        s.push_back(x ^ y);
        used.insert(y);
        used.insert(x ^ y);
    }
    return s;
}

ll fast(ll n) {
    ll k = (n - 1) / 3;
    vector<ll> path;
    while (k > 0) {
        ll pk = (k - 1) / 4;
        path.push_back(k - 4 * pk);
        k = pk;
    }
    reverse(path.begin(), path.end());
    ll a = 1, b = 2, c = 3;
    for (ll t : path) {
        if (t == 1) {
            a = 4 * a, b = 4 * b, c = 4 * c;
        } else if (t == 2) {
            a = 4 * a + 1, b = 4 * b + 2, c = 4 * c + 3;
        } else if (t == 3) {
            a = 4 * a + 2, b = 4 * b + 3, c = 4 * c + 1;
        } else if (t == 4) {
            a = 4 * a + 3, b = 4 * b + 1, c = 4 * c + 2;
        }
    }
    n--;
    if (n % 3 == 0) {
        return a;
    } else if (n % 3 == 1) {
        return b;
    } else if (n % 3 == 2) {
        return c;
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    vector<int> a = slow(10000);
//
//    for (int i = 1; i < (int) a.size(); i++) {
////        cout << i << " : " << a[i - 1] << " " << fast(i) << "\n";
//        if (a[i - 1] != fast(i)) {
//            cout << "WA\n";
//            cout << i << " " << a[i - 1] << fast(i) << "\n";
//            return 0;
//        }
//    }

    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
//        n = inf64 / 100;
        cout << fast(n) << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

//#define TEST

vector<vector<ll>> a;

#ifdef TEST
mt19937 rnd(42);
vector<pii> exp_path;
#endif

ll ask() {
#ifdef TEST
    ll res = 0;
    int n = (int) a.size();
    exp_path.clear();
    for (int i = 0, j = 0;;) {
        res += a[i][j];
        exp_path.emplace_back(i + 1, j + 1);
        if (i + 1 == n && j + 1 == n)
            break;
        if (i + 1 == n) j++;
        else if (j + 1 == n) i++;
        else {
            if (rnd() % 2) i++;
            else j++;
        }
    }
    cout << "k = " << res << endl;
    return res;
#else
    ll res;
    cin >> res;
    return res;
#endif
}

vector<pii> ans(ll k) {
    vector<pii> path;
    int i = 0, j = 0;
    int n = (int) a.size();
    while (1) {
        path.emplace_back(i + 1, j + 1);
        if (i + 1 == n && j + 1 == n)
            break;
        if (i + 1 == n) j++;
        else if (j + 1 == n) i++;
        else {
            if ((1ll << (i + j + 1)) & k) {
                if (a[i + 1][j]) i++;
                else j++;
            } else {
                if (a[i + 1][j]) j++;
                else i++;
            }
        }
    }
    return path;
}

int main() {

//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const ll MAXX = 1e16;

#ifdef TEST
    int n = 25;
#else
    int n;
    cin >> n;
#endif
    a.assign(n, vector<ll>(n, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + 1 < n; j++) {
            int d = i + j;
            if (!a[i - 1][j + 1])
                a[i][j] = 1ll << d;
            assert(0 <= a[i][j] && a[i][j] <= MAXX);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout.flush();

#ifdef TEST
    int q = 1000;
#else
    int q;
    cin >> q;
#endif

#ifdef TEST
    int cnt_ok = 0;
#endif

    for (int it = 0; it < q; it++) {
        ll k = ask();
        vector<pii> path = ans(k);
        for (auto [i, j] : path)
            cout << i << " " << j << "\n";
        cout.flush();
#ifdef TEST
        if (path == exp_path) {
            cnt_ok++;
            cout << "OK" << endl;
        } else {
            cout << "WA" << endl;
        }
#endif
    }

#ifdef TEST
    cout << cnt_ok << " / " << q << " passed" << endl;
#endif

    return 0;
}
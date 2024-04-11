#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 25, inf = 1000111222;

ll f[max_n][max_n];

int n, m;
ll k;

ll ans = 0;

vector<ll> v1, v2;

void f1(int i, int j, int fi, int fj, ll xr) {
    if (i == fi && j == fj) {
        v1.PB(xr);
        return;
    }
    if (i < fi) {
        f1(i + 1, j, fi, fj, xr ^ f[i + 1][j]);
    }
    if (j < fj) {
        f1(i, j + 1, fi, fj, xr ^ f[i][j + 1]);
    }
}

void f2(int i, int j, int fi, int fj, ll xr) {
    if (i == fi && j == fj) {
        v2.PB(xr);
        return;
    }
    if (i > fi) {
        f2(i - 1, j, fi, fj, xr ^ f[i - 1][j]);
    }
    if (j > fj) {
        f2(i, j - 1, fi, fj, xr ^ f[i][j - 1]);
    }
}

void process(int i, int j) {
    v1.clear();
    v2.clear();
    f1(0, 0, i, j, f[0][0]);
    f2(n - 1, m - 1, i, j, f[n - 1][m - 1]);
    sort(v2.begin(), v2.end());

    for (int ind = 0; ind < v1.size(); ++ind) {
        ll other = v1[ind] ^ f[i][j] ^ k;
        auto it1 = lower_bound(v2.begin(), v2.end(), other);
        if (it1 == v2.end() || *it1 > other) continue;
        auto it2 = lower_bound(v2.begin(), v2.end(), other + 1);
        ans += (it2 - it1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (n < m) {
                cin >> f[j][i];
            } else {
                cin >> f[i][j];
            }
        }
    }
    if (n < m) {
        swap(n, m);
    }

    for (int i = (m + n - 2) / 2, j = 0; j < m; --i, ++j) {
        process(i, j);
    }

    cout << ans;
    return 0;
}
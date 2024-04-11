
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1005;
int n, m, q;
string s[N];
ll tab[N][N];

ll rect(ll x1, ll y1, ll x2, ll y2) {
    return tab[x2][y2] - tab[x2][y1 - 1] - tab[x1 - 1][y2] + tab[x1 - 1][y1 - 1];
}

ll query(ll x, ll y, int rot, ll s) {
    // if(x == 0 || y == 0) return 0;
    ll nn = s * n, mm = s * m;
    if(rot % 2 == 1) swap(nn, mm);
    if(s == 0) {
        if(rot == 0) {
            return tab[x][y];
        }else if(rot == 1) {
            return rect(1, m - x + 1, y, m);
        }else if(rot == 2) {
            return rect(n - x + 1, m - y + 1, n, m);
        }else if(rot == 3) {
            return rect(n - y + 1, 1, n, x);
        }
    }
    ll xr = x - nn;
    ll yr = y - mm;
    if(xr > 0 && yr > 0) {
        ll v = query(nn - xr, mm - yr, (rot + 2) % 4, s / 2);
        return xr * mm + yr * nn + (rot % 2 == 1 ? (nn - xr) * (mm - yr) - v : v);
    }else if(xr > 0 && yr <= 0) {
        ll v = query(y, nn - xr, (rot + 3) % 4, s / 2);
        return xr * y + (rot % 2 == 1 ? y * (nn - xr) - v : v);
    }else if(xr <= 0 && yr > 0) {
        ll v = query(mm - yr, x, (rot + 1) % 4, s / 2);
        return yr * x + (rot % 2 == 1 ? (mm - yr) * x - v : v);
    }else {
        ll v = query(x, y, rot, s / 2);
        return (rot % 2 == 1 ? x * y - v : v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    s[0].assign(m + 1, '0');
    rep(i, 1, n + 1) {
        cin >> s[i];
        s[i] = "0" + s[i];
    }
    rep(i, 1, n + 2) {
        rep(j, 1, m + 2) {
            tab[i][j] = tab[i - 1][j] + tab[i][j - 1] - tab[i - 1][j - 1] + (i <= n && j <= m && s[i][j] == '1');
        }
    }
    while(q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x2, y2, 0, 1LL << 30) - query(x1 - 1, y2, 0, 1LL << 30)
            - query(x2, y1 - 1, 0, 1LL << 30) + query(x1 - 1, y1 - 1, 0, 1LL << 30) << '\n';
        // cout << query(x2, y2, 0, 1LL << 30) << ' ' << query(x1 - 1, y2, 0, 1LL << 30)
        //       << ' ' << query(x2, y1 - 1, 0, 1LL << 30) << ' ' << query(x1 - 1, y1 - 1, 0, 1LL << 30) << '\n';
        // cout << query(x2, y1 - 1, 0, 1LL << 30) << '\n';
    }
}
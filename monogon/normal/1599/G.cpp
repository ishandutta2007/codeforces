
#pragma GCC optimize ("Ofast")

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

using ftype = double;

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    ftype dist() const {
        return hypotl(x, y);
    }
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    ll cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    ll dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8);
    int n, k;
    cin >> n >> k;
    k--;
    vector<pt> p(n);
    rep(i, 0, n) cin >> p[i].x >> p[i].y;
    int a = 0, b = 1;
    int cnt = 0;
    rep(i, 0, n) {
        if((p[i] - p[a]).cross(p[b] - p[a]) == 0) {
            cnt++;
        }
    }
    if(cnt < n - 1) b = 2;
    cnt = 0;
    rep(i, 0, n) {
        if((p[i] - p[a]).cross(p[b] - p[a]) == 0) {
            cnt++;
        }
    }
    if(cnt < n - 1) a = 1;

    vi ve1, ve2;
    rep(i, 0, n) {
        if((p[i] - p[a]).cross(p[b] - p[a]) != 0) {
            ve1.push_back(i);
        }else {
            ve2.push_back(i);
        }
    }
    assert(sz(ve1) == 1);

    sort(all(ve2), [&](int i, int j) {
        return (p[i] - p[j]).dot(p[b] - p[a]) < 0;
    });
    vi v;
    ftype ans = DBL_MAX;

    if(k != ve1[0]) {
        ans = min(ans, (p[k] - p[ve2[0]]).dist() + (p[ve2[0]] - p[ve2.back()]).dist() + (p[ve2.back()] - p[ve1[0]]).dist());
        ans = min(ans, (p[k] - p[ve2.back()]).dist() + (p[ve2[0]] - p[ve2.back()]).dist() + (p[ve2[0]] - p[ve1[0]]).dist());
    }else {
        ans = min(ans, (p[k] - p[ve2[0]]).dist() + (p[ve2[0]] - p[ve2.back()]).dist());
        ans = min(ans, (p[k] - p[ve2.back()]).dist() + (p[ve2[0]] - p[ve2.back()]).dist());
        cout << ans << '\n';
        return 0;
    }

    vector<vi> kys = {
        {0, 1, 2, 3, 4, 5},
        {0, 2, 1, 3, 4, 5},
        {0, 1, 2, 3, 5, 4},
        {0, 2, 1, 3, 5, 4},
        {0, 4, 5, 3, 1, 2},
        {0, 5, 4, 3, 1, 2},
        {0, 4, 5, 3, 2, 1},
        {0, 5, 4, 3, 2, 1},
    };
    v.resize(6);
    v[0] = k;
    v[1] = ve2[0];
    v[3] = ve1[0];
    v[5] = ve2.back();
    rep(j, 1, sz(ve2)) {
        v[2] = ve2[j - 1];
        v[4] = ve2[j];
        rep(perm, 0, sz(kys)) {
            ftype dist = 0;
            rep(i, 1, 6) {
                dist += (p[v[kys[perm][i]]] - p[v[kys[perm][i - 1]]]).dist();
            }
            ans = min(ans, dist);
        }
    }
    cout << ans << '\n';
}
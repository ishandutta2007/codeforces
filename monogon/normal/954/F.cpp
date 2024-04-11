
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int M = 1e9 + 7;

struct mat3 {
    ll a[3][3];
    mat3() {
        rep(i, 0, 3) rep(j, 0, 3) {
            a[i][j] = 0;
        }
    }
    void iden() {
        rep(i, 0, 3) rep(j, 0, 3) {
            a[i][j] = (i == j);
        }
    }
    mat3 operator*(const mat3 &o) const {
        mat3 m;
        rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) {
            m.a[i][j] = (m.a[i][j] + a[i][k] * o.a[k][j]) % M;
        }
        return m;
    }
};

int n, a;
ll m, l, r, T = 1;
vector<pair<ll, int>> ve;
ll ways[3] = {0, 1, 0}, obst[3] = {0, 0, 0};
mat3 adj;

void upd(ll t) {
    mat3 mat, adjcpy;
    mat.iden();
    rep(i, 0, 3) rep(j, 0, 3) adjcpy.a[i][j] = adj.a[i][j];
    while(t > 0) {
        if(t & 1) {
            mat = mat * adjcpy;
        }
        adjcpy = adjcpy * adjcpy;
        t /= 2;
    }
    ll ways2[3] = {0, 0, 0};
    rep(i, 0, 3) rep(j, 0, 3) {
        ways2[i] = (ways2[i] + mat.a[i][j] * ways[j]) % M;
    }
    rep(i, 0, 3) ways[i] = ways2[i];
}

void fix() {
    rep(i, 0, 3) rep(j, 0, 3) {
        adj.a[i][j] = (abs(i - j) <= 1 && obst[i] == 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a >> l >> r;
        ve.emplace_back(l - 1, -a);
        ve.emplace_back(r, a);
    }
    fix();
    sort(all(ve));
    for(auto &p : ve) {
        auto [ti, a] = p;
        upd(ti - T);
        T = ti;
        if(a < 0) {
            // remove row
            a = -a - 1;
            obst[a]++;
        }else {
            // add row
            a--;
            obst[a]--;
        }
        fix();
    }
    upd(m - T);
    cout << ways[1] << '\n';
}
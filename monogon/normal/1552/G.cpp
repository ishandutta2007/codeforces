
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v(k);
    rep(i, 0, k) {
        int len;
        cin >> len;
        v[i].push_back(0);
        rep(j, 0, len) {
            int x;
            cin >> x;
            x--;
            v[i].push_back(v[i].back() | (1LL << x));
        }
    }
    struct quant {
        ll m, p;
        quant() {
            m = p = 0;
        }
        ll getQ(int n) const {
            return ((1LL << n) - 1) ^ m ^ p;
        }
        bool sorted(int n) const {
            ll q = getQ(n);
            ll P = p + (1LL << n);
            if(q == 0) return m <= (P & -P);
            return m <= q && q <= (P & -P) && __builtin_popcountll(q) <= 1;
        }
    };
    auto dfs = [&](auto dfs, int i, quant Q) -> bool {
        if(i == k) {
            return Q.sorted(n);
        }
        ll mask = v[i].back();
        int minus = __builtin_popcountll(mask & Q.m);
        int plus = __builtin_popcountll(mask & Q.p);
        int len = sz(v[i]) - 1;
        rep(cnt, minus, len - plus + 1) {
            Q.m = (Q.m & ~mask) | v[i][cnt];
            Q.p = (Q.p & ~mask) | (mask ^ v[i][cnt]);
            bool b = dfs(dfs, i + 1, Q);
            if(!b) return false;
        }
        return true;
    };
    cout << (dfs(dfs, 0, quant()) ? "ACCEPTED\n" : "REJECTED\n");
}
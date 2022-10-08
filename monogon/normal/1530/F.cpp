
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

const int M = 31607, N = 21;

int val[N][1 << N], col[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> a(n, vi(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
            a[i][j] *= 3973;
            a[i][j] %= M;
        }
    }
    rep(i, 0, n) val[i][0] = 1;
    rep(s, 1, 1 << n) {
        int bit = 0;
        while(~s >> bit & 1) bit++;
        rep(i, 0, n) {
            val[i][s] = (a[i][bit] * val[i][s ^ (1 << bit)]) % M;
        }
    }
    rep(i, 0, n) {
        col[i] = 1;
        rep(j, 0, n) {
            col[i] = (col[i] * a[j][i]) % M;
        }
    }
    int mask = (1 << n) - 1;
    int ans = 1;
    rep(i, 0, n) {
        ans = (ans * (1 - val[i][mask])) % M;
    }
    ans = (1 - ans) % M;
    rep(s, 1, 1 << (n + 2)) {
        int x = 1;
        rep(i, 0, n) {
            if(s >> i & 1) x = (x * col[i]) % M;
            int s2 = s & mask;
            if((s >> n & 1) && (~s2 >> i & 1)) {
                s2 |= (1 << i);
                x = (x * a[i][i]) % M;
            }
            if((s >> (n + 1) & 1) && (~s2 >> (n - i - 1) & 1)) {
                s2 |= (1 << (n - i - 1));
                x = (x * a[i][n - i - 1]) % M;
            }
            x = (x * (1 - val[i][mask - s2])) % M;
        }
        if(__builtin_popcount(s) % 2 == 1) ans = (ans + x) % M;
        else ans = (ans - x) % M;
    }
    ans = (ans + M) % M;
    cout << ans << '\n';
}
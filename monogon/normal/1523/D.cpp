
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

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vi pos;
    vi A(1 << 15, 0);
    vi bestpos;
    int bestmask = 0;
    rep(it, 0, 50) {
        int idx = rand(0, n - 1);
        pos.clear();
        rep(i, 0, m) {
            if(s[idx][i] == '1') pos.push_back(i);
        }
        int p = sz(pos);
        rep(i, 0, 1 << p) A[i] = 0;
        rep(i, 0, n) {
            int mask = 0;
            rep(j, 0, p) {
                if(s[i][pos[j]] == '1') {
                    mask ^= (1 << j);
                }
            }
            A[mask]++;
        }
        rep(i, 0, p) {
            for(int mask = (1 << p) - 1; mask >= 0; mask--) {
                if(~mask >> i & 1) {
                    A[mask] += A[mask ^ (1 << i)];
                }
            }
        }
        rep(mask, 0, 1 << p) {
            if(A[mask] >= (n + 1) / 2 && __builtin_popcount(mask) >= __builtin_popcount(bestmask)) {
                bestpos = pos;
                bestmask = mask;
            }
        }
    }
    string ans(m, '0');
    rep(i, 0, sz(bestpos)) {
        if(bestmask >> i & 1) {
            ans[bestpos[i]] = '1';
        }
    }
    cout << ans << '\n';
}
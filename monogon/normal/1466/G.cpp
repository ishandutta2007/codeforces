
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

const int M = 1e9 + 7;

int occ(string s, const string &t) {
    s = t + "#" + s;
    int n = s.length();
    vi kmp(n, 0);
    int i = 1, j = 0;
    while(i < n) {
        if(s[i] == s[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
    int m = t.length(), cnt = 0;
    rep(i, 0, n) {
        if(kmp[i] == m) cnt++;
    }
    return cnt;
}

int n, q;
string s0, t;
vector<ll> pow2, pow2inv;
string ugh;
vector<array<int, 26>> smh;

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0 ) {
        if(b & 1) ans = (ans * a) %M ;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return powmod(a, M - 2);
}

ll solve(int pos, int step, int k0, int k) {
    int si = ugh.length();
    if(pos >= si) {
        return pow2[k - k0];
    }else if(k0 == k) {
        return 0;
    }else if(pos + step >= si) {
        return ((smh[k0][ugh[pos] - 'a'] - smh[k][ugh[pos] - 'a']) * pow2inv[n - k]) % M;
    }
    bool flag[2] = {true, true};
    bool b = true;
    char c = t[k0];
    for(int i = pos; i < si; i += step) {
        if(ugh[i] != c) flag[b] = false;
        b = !b;
    }
    ll ans = 0;
    if(flag[1]) {
        ans = solve(pos + step, min(si, step * 2), k0 + 1, k);
    }
    if(flag[0]) {
        ans = (ans + solve(pos, min(si, step * 2), k0 + 1, k)) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s0 >> t;
    int S = s0.length();

    pow2.assign(n + 1, 0);
    pow2inv.assign(n + 1, 0);
    pow2[0] = 1;
    pow2inv[0] = 1;
    pow2inv[1] = modinv(2);
    rep(i, 1, n + 1) pow2[i] = (2 * pow2[i - 1]) % M;
    rep(i, 2, n + 1) {
        pow2inv[i] = (pow2inv[1] * pow2inv[i - 1]) % M;
    }

    smh.resize(n + 1);
    rep(c, 0, 26) smh[n][c] = 0;
    for(int i = n - 1; i >= 0; i--) {
        rep(c, 0, 26) {
            smh[i][c] = (smh[i + 1][c] + (t[i] - 'a' == c ? pow2[n - i - 1] : 0)) % M;
        }
    }

    while(q--) {
        int k;
        string w;
        cin >> k >> w;
        int m = w.length();
        // occurs inside s0?
        ll ans = 0;
        if(m <= S) {
            int cnt = occ(s0, w);
            ans = (ans + pow2[k] * cnt) % M;
        }
        // try cyclic shifts of ? s0 ? s0 ? s0
        int si = min(m, S + 1);
        for(int off = 0; off < si; off++) {
            bool flag = true;
            for(int i = 0; i < si && flag; i++) {
                if(i == off) continue;
                char c = s0[(i - off + S + 1) % (S + 1) - 1];
                for(int j = i; j < m; j += S + 1) {
                    if(w[j] != c) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                ugh.clear();
                for(int i = off; i < m; i += S + 1) {
                    ugh.push_back(w[i]);
                }
                ans = (ans + solve(0, 1, 0, k)) % M;
            }
        }

        ans = (ans + M) % M;
        cout << ans << '\n';
    }
}
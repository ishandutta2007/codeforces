#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e6 + 10;
int b[maxN];
int m[maxN];
int lp[maxN];
int cnt[maxN];
int pows[maxN];
int n, k;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
vector < int > pr;
void calc() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    for (int i = 1; i <= k; i++) {
        pows[i] = pw(i, n);
    }
}
int ans[(1 << 18)];
int q[(1 << 18)];
void solve(int x) {
    b[x] = b[x - 1];
    int prv = -1;
    vector < int > primes;
    int cop = x;
    while (x > 1) {
        int p = lp[x];
        if (p != prv) {
            prv = p;
            primes.push_back(p);
        }
        x /= lp[x];
    }
    x = cop;
    for (int i = 0; i < (1 << (primes.size())); i++) {
        ans[i] = 0;
        q[i] = 0;
    }
    ans[0] = 1;
    q[0] = 1;
    b[x] = sum(b[x], sub(pows[x], cnt[1]));
    cnt[1] = pows[x];
    for (int i = 1; i < (1 << (primes.size())); i++) {
        for (int j = 0; j < primes.size(); j++) {
            if (i & (1 << j)) {
                ans[i] = ans[i ^ (1 << j)] * primes[j];
                q[i] = -q[i ^ (1 << j)];
                int t = pows[x / (ans[i])];
                if (q[i] > 0) {
                    b[x] = sum(b[x], sub(t, cnt[ans[i]]));
                }
                else b[x] = sub(b[x], sub(t, cnt[ans[i]]));
                cnt[ans[i]] = t;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    calc();
    for (int i = 1; i <= k; i++) {
        solve(i);
    }
    //cout << b[1] << " " << b[2] << endl;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = sum(ans, (b[i] ^ i));
    }
    cout << ans;
    return 0;
}
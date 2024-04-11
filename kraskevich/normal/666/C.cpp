#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 1000 * 1000 * 1000 + 7;
const int N = 100 * 1000 + 10;
const int B = 500;

int sum[B][N];
int p25[N];
int f[N];
int rf[N];
map<int, int> id;
int last;
int cur;

int madd(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int msub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mmul(int a, int b) {
    return a * 1ll * b % MOD;
}

ll bin_pow(ll x, ll n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n & 1)
            res = mmul(res, x);
        x = mmul(x, x);
    }
    return res;
}

ll inv(ll x) {
    assert (x != 0);
    ll r = bin_pow(x, MOD - 2);
    assert (mmul(x, r) == 1);
    return r;
}

void init() {
    rf[0] = f[0] = 1;
    p25[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = mmul(f[i - 1], i);
        p25[i] = mmul(p25[i - 1], 25);
        rf[i] = inv(f[i]);
    }
}

ll cnk(int n, int k) {
    assert (n >= k);
    return mmul(mmul(f[n], rf[k]), rf[n - k]);
}

void calc(int m) {
    if (id.count(m)) {
        cur = id[m];
        return;
    }
    cur = id[m] = last++;
    sum[cur][m] = 1;
    for (int i = m + 1; i < N; i++) {
        sum[cur][i] = mmul(sum[cur][i - 1], 26);
        sum[cur][i] = madd(sum[cur][i], mmul(cnk(i - 1, m - 1), p25[i - m])); 
    }
}

int get_ans(int n) {
    return sum[cur][n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int q;
    string s;
    cin >> q >> s;
    calc(s.length());
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> s;
            calc(s.length());
        } else {
            int n;
            cin >> n;
            cout << get_ans(n) << "\n";
        }
    }
}
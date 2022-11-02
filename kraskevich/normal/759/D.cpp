#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 5055;

int c[2 * N][N];

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

void init() {
    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= min(i, N - 1); j++) {
            c[i][j] = c[i - 1][j];
            if (j)
                c[i][j] = madd(c[i][j], c[i - 1][j - 1]);        
        }    
    }
}

int f[N][26];
int tot[N];
int n;
int a[N];
int res;

int ways(int n, int k) {
    n -= k;
    return c[n + k - 1][k - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';
    tot[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int len = n; len >= 1; len--) {
            int add = msub(tot[len - 1], madd(f[len][a[i]], f[len - 1][a[i]]));
            f[len][a[i]] = madd(f[len][a[i]], add);
            tot[len] = madd(tot[len], add);
        }        
    }
    for (int len = 1; len <= n; len++) {
        res = madd(res, mmul(ways(n, len), tot[len]));    
    }
    cout << res << endl;
}
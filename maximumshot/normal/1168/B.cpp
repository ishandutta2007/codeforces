#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 21;
const int P = 7;

const int N = 3e5 + 5;

int n;
char s[N];
int h1[N], h2[N];
int pw[N];
int r[N];

int get_hash1(int l, int r) {
    int res = (h1[r] - 1ll * pw[r - l + 1] * h1[l - 1]) % mod;
    if (res < 0) res += mod;
    return res;
}

int get_hash2(int l, int r) {
    l = n - l + 1;
    r = n - r + 1;
    swap(l, r);
    int res = (h2[r] - 1ll * pw[r - l + 1] * h2[l - 1]) % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {

    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = (1ll * pw[i - 1] * P) % mod;
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> (s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        r[i] = 0;
        while (i - r[i] > 1 && i + r[i] < n && (s[i] != s[i - r[i] - 1] || s[i] != s[i + r[i] + 1])) {
            r[i]++;
        }
    }

    vector<vector<int>> add(n + 1);

    for (int i = 1; i <= n; i++) {
        if (i - r[i] - 1 >= 1 && i + r[i] + 1 <= n) {
            add[i + r[i] + 1].push_back(i - r[i] - 1);
//            cout << i - r[i] - 1 << " .. " << i + r[i] + 1 << "\n";
        }
    }

    ll res = 0;

    for (int mx = 0, qr = 1; qr <= n; qr++) {
        for (int ql : add[qr]) {
            mx = max(mx, ql);
        }
        res += mx;
    }

    cout << res << "\n";

    return 0;
}
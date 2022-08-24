#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 9000;

char s[MAXN];
int gg[MAXN];
int go[MAXN];
char t[MAXN];
int dp[MAXN];
int z[MAXN];

void zz(char *s, int n) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (r > i)
            z[i] = min(r - i, z[i - l]);
        else
            z[i] = 0;
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] > r)
            r = i + z[i], l = i;
    }
    z[n] = 0;
}

int main() {
    cin >> s;
    int n = strlen(s);
    fill(dp, dp + n + 1, 100000);
    for (int i = 0; i <= n; ++i) {
        int cnt = 0;
        int x = i;
        while (x)
            x /= 10, ++cnt;
        gg[i] = cnt;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j)
            t[j - i] = s[j];
        int m = n - i;
        t[m] = 0;
        zz(t, m);
        for (int j = 0; j <= m; ++j)
            go[j] = 0;
        for (int j = 1; j <= m; ++j) {
            for (int k = j; !go[k] && k <= m && j + z[j] >= k; k += j) {
                dp[i + k] = min(dp[i] + gg[k / j] + j, dp[i + k]);
                go[k] = 1;
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
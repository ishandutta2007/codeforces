#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int k, n;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 3005;
int dp[maxN][maxN];
int m;
int c[maxN];
bool is_good(int i, int j) {
    if ((j - i + 1) != 4) return true;
    int f = c[i] +  2 * c[i + 1] + 4 * c[i + 2] + 8 * c[i + 3];
    if (f == 12 || f == 10 || f == 7 || f == 15) return false;
    return true;
}
int sz = 2;
struct node{
    int nxt[2];
    node() {
        nxt[0] = nxt[1] = -1;
    }
};
node v[maxN * maxN];
int val[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        c[i] = t - '0';
    }
    for (int i = 1; i <= n; i++) {
        val[i][i - 1] = 1;
        for (int j = i; j <= n; j++) {
            for (int k = max(j - 3, i); k <= j; k++) {
                if (is_good(k, j)) {
                    val[i][j] = sum(val[i][j], val[i][k - 1]);
                }
            }
        }
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        int st = i;
        int cur = 1;
        int frst = -1;
        for (int j = i; j >= 1; j--) {
            if (v[cur].nxt[c[j]] == -1) {
                v[cur].nxt[c[j]] = sz;
                sz++;
                frst = max(frst, j);
                cur = v[cur].nxt[c[j]];
            }
            else {
                cur = v[cur].nxt[c[j]];
            }
        }
        for (int k = frst; k >= 1; k--) total = sum(total, val[k][i]);
        cout << total << '\n';
    }
}
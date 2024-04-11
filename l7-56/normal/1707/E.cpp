#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 2e5 + 10, T = 25;
int n, q, a[maxn], lg2[maxn];
pii f[T][T][maxn];
pii merge(pii a, pii b) { return {min(a.fir, b.fir), max(a.sec, b.sec)}; }
pii query(int i, pii p) {
    int l = p.fir, r = p.sec, j = lg2[r - l + 1];
    return merge(f[i][j][l], f[i][j][r - (1 << j) + 1]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= n; ++i) f[0][0][i] = {a[i], a[i]};
    for (int j = 1; j < T; ++j)
        for (int k = 1; k + (1 << j) - 1 <= n; ++k)
            f[0][j][k] = merge(f[0][j - 1][k], f[0][j - 1][k + (1 << (j - 1))]);
    for (int i = 1; i < T; ++i)
        for (int j = 0; j < T; ++j)
            for (int k = 1; k + (1 << j) - 1 <= n; ++k)
                f[i][j][k] = query(i - 1, f[i - 1][j][k]);
    while (q--) {
        pii p; scanf("%d%d", &p.fir, &p.sec);
        if (p == pii(1, n)) { printf("0\n"); continue; }
        int ans = 0;
        for (int i = T - 1; i >= 0; --i) {
            pii np = query(i, p);
            if (np != pii(1, n)) p = np, ans += (1 << i);
        }
        p = query(0, p), ++ans;
        printf("%d\n", p == pii(1, n) ? ans : -1);
    }
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 2010, mod = 998244353;
int n, deg[maxn];
char mp[maxn][maxn];

int check() {
    vi p(n);
    iota(begin(p), end(p), 1);
    sort(begin(p), end(p), [&] (int x, int y) { return deg[x] < deg[y]; });
    for (int i = 1, sum = 0; i < n; ++i) {
        sum += deg[p[i - 1]];
        if (sum == i * (i - 1) / 2) return 0;
    }
    return 1;
}
void rev(int x) {
    for (int i = 1; i <= n; ++i) {
        deg[x] -= (mp[x][i] == '1'), deg[i] -= (mp[i][x] == '1');
        mp[x][i] ^= 1, mp[i][x] ^= 1;
        deg[x] += (mp[x][i] == '1'), deg[i] += (mp[i][x] == '1');
    }
}

int main() {
	// freopen("rv.in", "r", stdin), freopen("rv.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            deg[i] += (mp[i][j] == '1');
    if (check()) return printf("0 1\n"), 0;
    if (n <= 6) {
        int ans1 = n + 1, ans2 = 0;
        for (int s = 0; s < (1 << n); ++s) {
            int res = 0;
            for (int i = 1; i <= n; ++i) if ((s >> (i - 1)) & 1) res++, rev(i);
            if (check()) {
                if (ans1 > res) ans1 = res, ans2 = 1;
                else if (ans1 == res) ans2++;
            }
            for (int i = 1; i <= n; ++i) if ((s >> (i - 1)) & 1) rev(i);
        }
        if (ans2) {
            for (int i = 2; i <= ans1; ++i) ans2 = (ll) ans2 * i % mod;
            printf("%d %d\n", ans1, ans2);
        }
        else printf("-1\n");
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        rev(i), ans += check(), rev(i);
    printf("1 %d\n", ans);
	return 0;
}
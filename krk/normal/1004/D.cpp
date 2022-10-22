#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int T;
int mx;
int cnt[Maxn], has[Maxn];
ll sum;

ll Get(int r, int n) { return ll(r) * (r + 1) / 2 + ll(n - r) * (n - r - 1) / 2; }

bool Check(int r, int c, int n, int m)
{
    ll my = ll(m) * Get(r, n) + ll(n) * Get(c, m);
    if (ll(m) * Get(r, n) + ll(n) * Get(c, m) != sum) return false;
    fill(has, has + mx + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int val = abs(i - r) + abs(j - c);
            if (val > mx) return false;
            if (has[val] == cnt[val]) return false;
            has[val]++;
        }
    return true;
}

int main()
{
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a; scanf("%d", &a);
        mx = max(mx, a);
        cnt[a]++;
        sum += a;
    }
    for (int n = 1; n * n <= T; n++) if (T % n == 0) {
        int m = T / n;
        for (int r = 0; r < n; r++) {
            int c = mx - r;
            if (c < 0 || c >= m) continue;
            if (Check(r, c, n, m)) {
                printf("%d %d\n", n, m);
                printf("%d %d\n", r + 1, c + 1);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 300005, N = 300000;
int n;
int a[maxn];
int c[maxn];
ll d[maxn];
const int B = 600;
ll cnt[B];

void add(int x) {
    int v = x;
    for (; x <= N; x += x & -x) {
        ++c[x];
        d[x] = d[x] + v;
    }
}

pair<int, ll> ask(int x) {
    int a1 = 0;
    ll a2 = 0;
    for (; x; x -= x & -x) {
        a1 += c[x];
        a2 += d[x];
    }
    return mkp(a1, a2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= B) {
            pair<int, ll> last = {0, 0};
            int lj = 0;
            for (int j = a[i] - 1;; j = min(N, j + a[i])) {
                auto t = ask(j);
                ans += t.se - last.se - (ll)(t.fi - last.fi) * (j / a[i]) * a[i];
                last = t;
                if (j == N) break;
            }
        } else {
            ans += cnt[a[i]];
        }
        // printf("%I64d ", ans);
        {
            pair<int, ll> last = {0, 0};
            for (int j = 1, k; j <= a[i]; j = k + 1) {
                k = a[i] / (a[i] / j);
                auto t = ask(k);
                // printf("a[i]=%d, [%d, %d] [%d, %I64d]\n", a[i], j, k, t.fi, t.se);
                ans += (ll)a[i] * (t.fi - last.fi) - (ll)(t.se - last.se) * (a[i] / j);
                // printf("ans=%I64d\n", ans);
                last = t;
            }
            ans += (ll)(i - last.fi) * a[i];
        }

        printf("%I64d ", ans);
        add(a[i]);
        for (int b = 1; b < B; ++b) {
            cnt[b] += a[i] % b;
        }
    }
    puts("");
    return 0;
}
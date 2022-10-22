#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];
int cnt[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(cnt, cnt + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        int r = 1, st = -n;
        int best = 1000000000;
        int ba, bb;
        for (int l = 1; l <= n; l++) {
            while (r <= n && st < k) {
                st += 2 * cnt[r];
                r++;
            }
            if (st >= k && r - l < best) {
                best = r - l;
                ba = l; bb = r - 1;
            }
            st -= 2 * cnt[l];
        }
        printf("%d %d\n", ba, bb);
        st = 0;
        int nxt = 1, nd = 1;
        for (int i = 1; i <= n && nd < k; i++) {
            if (ba <= a[i] && a[i] <= bb) st++;
            else st--;
            if (st == nd) {
                printf("%d %d\n", nxt, i);
                nd++;
                nxt = i + 1;
            }
        }
        printf("%d %d\n", nxt, n);
    }
    return 0;
}
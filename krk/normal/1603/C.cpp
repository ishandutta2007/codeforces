#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int mod = 998244353;

int T;
int n;
int a[Maxn];
int sum[Maxn];
int cur, slen[2];
ii seq[2][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int tres = 0;
        slen[cur] = 0;
        seq[cur][slen[cur]++] = ii(0, 0);
        for (int ind = 0; ind < n; ind++) {
            scanf("%d", &a[ind]);
            cur = !cur;
            slen[cur] = 0;
            int pnt = 0;
            for (int i = 1; i < a[ind]; ) {
                int tims = (a[ind] - 1) / i + 1;
                int nxt = a[ind] / tims;
                while (pnt + 1 < slen[!cur] && seq[!cur][pnt + 1].first <= nxt)
                    pnt++;
                int res = (seq[!cur][pnt].second + ll(ind + 1) * (tims - 1)) % mod;
                seq[cur][slen[cur]++] = ii(i, res);
                i = (a[ind] - 1) / ((a[ind] - 1) / i) + 1;
            }
            while (pnt + 1 < slen[!cur] && seq[!cur][pnt + 1].first <= a[ind])
                pnt++;
            int res = seq[!cur][pnt].second;
            tres = (tres + res) % mod;
            seq[cur][slen[cur]++] = ii(a[ind], res);
        }
        printf("%d\n", tres);
    }
    return 0;
}
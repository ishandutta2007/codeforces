#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 10;
const int Maxm = 10005;
const int Maxs = 25;
const int nil = 11;

int T;
int n, m;
ll x[Maxn];
char str[Maxn][Maxm];
int my[Maxm];
int seq[Maxs][Maxm];
int slen[Maxs];
int cur[Maxm];
ll res;
int ans[Maxm];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%I64d", &x[i]);
        res = -1;
        for (int i = 0; i < n; i++)
            scanf("%s", str[i]);
        for (int mask = 0; mask < 1 << n; mask++) {
            ll cand = 0;
            for (int i = 0; i < n; i++) {
                int delt;
                if (mask & 1 << i) {
                    cand -= x[i];
                    delt = 1;
                } else {
                    cand += x[i];
                    delt = -1;
                }
                for (int j = 0; j < m; j++)
                    if (str[i][j] == '1')
                        my[j] += delt;
            }
            for (int j = 0; j < m; j++) {
                seq[my[j] + nil][slen[my[j] + nil]++] = j;
                my[j] = 0;
            }
            int pnt = 1;
            for (int i = 0; i < Maxs; i++) {
                for (int j = 0; j < slen[i]; j++) {
                    cur[seq[i][j]] = pnt;
                    cand += (i - nil) * pnt;
                    pnt++;
                }
                slen[i] = 0;
            }
            if (cand > res) {
                res = cand;
                for (int i = 0; i < m; i++)
                    ans[i] = cur[i];
            }
        }
        for (int i = 0; i < m; i++)
            printf("%d%c", ans[i], i + 1 < m? ' ': '\n');
    }
    return 0;
}
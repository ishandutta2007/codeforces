#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 100005;

int n, m, k;
vector <int> rows[Maxn], cols[Maxn];
ll vis;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x, y; scanf("%d %d", &x, &y);
        rows[x].push_back(y);
        cols[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        sort(rows[i].begin(), rows[i].end());
    for (int j = 1; j <= m; j++)
        sort(cols[j].begin(), cols[j].end());
    int r1 = 1, r2 = n, c1 = 1, c2 = m, ang = 0;
    while (r1 <= r2 && c1 <= c2) {
        if (ang == 0) {
            int ind = lower_bound(rows[r1].begin(), rows[r1].end(), c1) - rows[r1].begin();
            int en = ind < rows[r1].size()? rows[r1][ind]: Inf;
            en = min(en, c2 + 1);
            vis += en - c1;
            r1++; c2 = en - 1;
        } else if (ang == 1) {
            int ind = lower_bound(cols[c2].begin(), cols[c2].end(), r1) - cols[c2].begin();
            int en = ind < cols[c2].size()? cols[c2][ind]: Inf;
            en = min(en, r2 + 1);
            vis += en - r1;
            c2--; r2 = en - 1;
        } else if (ang == 2) {
            int ind = upper_bound(rows[r2].begin(), rows[r2].end(), c2) - rows[r2].begin() - 1;
            int en = ind >= 0? rows[r2][ind]: -Inf;
            en = max(en, c1 - 1);
            vis += c2 - en;
            r2--; c1 = en + 1;
        } else if (ang == 3) {
            int ind = upper_bound(cols[c1].begin(), cols[c1].end(), r2) - cols[c1].begin() - 1;
            int en = ind >= 0? cols[c1][ind]: -Inf;
            en = max(en, r1 - 1);
            vis += r2 - en;
            c1++; r1 = en + 1;
        }
        ang = (ang + 1) % 4;
    }
    if (vis + k == ll(n) * m) printf("Yes\n");
    else printf("No\n");
    return 0;
}
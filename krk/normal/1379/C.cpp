#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, m;
ii seq[Maxn];
ll sum[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &seq[i].first, &seq[i].second);
        sort(seq, seq + m);
        sum[m] = 0;
        for (int i = m - 1; i >= 0; i--)
            sum[i] = seq[i].first + sum[i + 1];
        ll res = 0;
        if (n <= m) res = sum[m - n];
        for (int i = 0; i < m; i++) {
            int ind = lower_bound(seq, seq + m, ii(seq[i].second, 0)) - seq;
            int tk = m - ind;
            ll s = sum[ind];
            if (i < ind) { tk++; s += seq[i].first; }
            if (tk <= n) {
                s += ll(seq[i].second) * (n - tk);
                res = max(res, s);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int a[Maxn];
int c[Maxn];
ii seq[Maxn];
int pnt;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        seq[i - 1] = ii(c[i], i);
    }
    sort(seq, seq + n);
    while (m--) {
        int t, d; scanf("%d %d", &t, &d);
        ll paid = 0;
        while (d > 0 && pnt < n) {
            if (a[t] > 0) {
                int tk = min(a[t], d);
                paid += ll(tk) * c[t]; a[t] -= tk;
                d -= tk;
            } else {
                int ind = seq[pnt].second;
                int tk = min(a[ind], d);
                paid += ll(tk) * c[ind]; a[ind] -= tk;
                d -= tk;
            }
            while (pnt < n && a[seq[pnt].second] == 0) pnt++;
        }
        if (d > 0) paid = 0;
        printf("%I64d\n", paid);
    }
    return 0;
}
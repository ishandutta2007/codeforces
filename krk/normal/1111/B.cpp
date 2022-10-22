#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;

int n, k, m;
int a[Maxn];
ld res;
ld sum;

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int pnt = n - 1, lft = k;
    m -= n;
    for (int i = n - 1; i >= 0; i--) {
        m++; sum += a[i];
        if (m < 0) continue;
        while (pnt >= i && m > 0) {
            int tk = min(lft, m);
            m -= tk; lft -= tk;
            sum += tk;
            if (lft == 0) {
                pnt--; lft = k;
            }
        }
        res = max(res, sum / ld(n - i));
    }
    cout << fixed << setprecision(15) << res << endl;
    return 0;
}
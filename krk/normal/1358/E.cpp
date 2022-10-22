#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int delt[Maxn];
int n;
int m;
int vals[Maxn];
int rem;
int x;

int main()
{
    scanf("%d", &n);
    m = (n + 1) / 2;
    rem = n / 2;
    for (int i = 0; i < m; i++)
        scanf("%d", &vals[i]);
    scanf("%d", &x);
    ll sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum += vals[i];
        if (x > 0)
            if (sum > 0)
                delt[1]++;
            else {
                ll nd = (-sum) / x + 1;
                nd += m - i;
                nd = min(nd, ll(m - i + rem + 1));
                if (nd <= n) delt[nd]++;
            }
        else if (x == 0)
                if (sum > 0)
                    delt[1]++;
                else {
                    int st = m - i + rem + 1;
                    if (st <= n) delt[st]++;
                }
        else if (sum > 0) {
            ll mx = (sum - 1) / (-x);
            if (mx >= rem) delt[1]++;
            else {
                delt[1]++;
                delt[m - i + mx + 1]--;
                int st = m - i + rem + 1;
                if (st <= n) delt[st]++;
            }
        } else {
            int st = m - i + rem + 1;
            if (st <= n) delt[st]++;
        }
    }
    int from = (n + 2) / 2;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += delt[i];
        if (cur >= m && i >= from) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 1000000000000000000ll;

int T;
int n, m;
int a[Maxn];
int delt[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int g = 0;
        for (int i = 0; i < m; i++) {
            int b; scanf("%d", &b);
            g = gcd(g, b);
        }
        ll ev = 0, od = 0;
        for (int i = 1; i <= g; i++) {
            ll mnneg = Inf, mnpos = Inf;
            int cnt = 0;
            ll sum = 0;
            for (int j = i; j <= n; j += g) {
                sum += abs(a[j]);
                if (a[j] < 0) {
                    cnt++;
                    mnneg = min(mnneg, -ll(a[j]));
                } else mnpos = min(mnpos, ll(a[j]));
            }
            if (cnt % 2) {
                od += sum;
                ev += sum - 2ll * min(mnneg, mnpos);
            } else {
                ev += sum;
                od += sum - 2ll * min(mnneg, mnpos);
            }
        }
        printf("%I64d\n", max(od, ev));
    }
    return 0;
}
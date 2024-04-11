#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 400005;

int sy, a, b;
int n, slen;
int seq[Maxn];
ll sum[Maxn];

ld getV(ld x, ld y, ld l)
{
    return l + (x - l) * ld(sy) / ld(y);
}

int main()
{
    scanf("%d %d %d", &sy, &a, &b);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int lef, rig; scanf("%d %d", &lef, &rig);
        sum[i] = sum[i - 1] + rig - lef;
        seq[slen++] = lef;
        seq[slen++] = rig;
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        int lef = 0, rig = slen - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (ll(a) * y > ll(seq[mid]) * y + ll(x) * sy - ll(seq[mid]) * sy)
                lef = mid + 1;
            else rig = mid - 1;
        }
        int L = lef;
        lef = 0, rig = slen - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (ll(b) * y < ll(seq[mid]) * y + ll(x) * sy - ll(seq[mid]) * sy)
                rig = mid - 1;
            else lef = mid + 1;
        }
        int R = rig;
        ld res = 0;
        if (L > R && L % 2) res = b - a;
        else {
            if (L % 2 && L <= R) {
                res += getV(x, y, seq[L]) - a;
                L++;
            }
            if (R % 2 == 0 && L <= R) {
                res += b - getV(x, y, seq[R]);
                R--;
            }
            if (L <= R)
                res += ld(sum[(R + 1) / 2] - sum[L / 2]) * (1.0l - ld(sy) / ld(y));
        }
        printf("%.10f\n", double(res));
    }
    return 0;
}
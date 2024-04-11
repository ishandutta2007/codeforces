#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld lim = 1e9 + 5;
const int Maxn = 100005;

int T;
int n, L;
int a[Maxn];

ld Get(ld tim)
{
    ld res = 0;
    ld rem = tim;
    int lst = 0, pnt = 0;
    int sp = 1;
    while (pnt < n && ld(a[pnt] - lst) / sp <= rem) {
        rem -= ld(a[pnt] - lst) / sp;
        res += a[pnt] - lst;
        lst = a[pnt++];
        sp++;
    }
    if (pnt >= n && ld(L - lst) / sp <= rem)
        return L + 1;
    res += rem * sp;
    rem = tim;
    lst = L, pnt = n - 1;
    sp = 1;
    while (pnt >= 0 && ld(lst - a[pnt]) / sp <= rem) {
        rem -= ld(lst - a[pnt]) / sp;
        res += lst - a[pnt];
        lst = a[pnt--];
        sp++;
    }
    if (pnt < 0 && ld(lst) / sp <= rem)
        return L + 1;
    res += rem * sp;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &L);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ld lef = 0, rig = lim;
        for (int i = 0; i < 70; i++) {
            ld mid = (lef + rig) / 2.0l;
            if (Get(mid) >= L) rig = mid;
            else lef = mid;
        }
        cout << fixed << setprecision(10) << rig << "\n";
    }
    return 0;
}
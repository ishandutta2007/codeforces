#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
typedef long long lld;

int H, Q, N;

struct Z{
    lld s, e; int t;
} A[MAXN];

int main()
{
    for (scanf("%d%d", &H, &Q);Q--;){
        int h, t;
        lld l, r;
        scanf("%d%lld%lld%d", &h, &l, &r, &t);
        for (int i=h;i<H;i++)
            l <<= 1, r = r+r+1;
        A[++N] = {l, r, t};
    }
    lld s = 1, e = 1;
    for (int i=1;i<H;i++) s <<= 1, e = e+e+1;
    for (int i=1;i<=N;i++) if (A[i].t)
        s = max(s, A[i].s), e = min(e, A[i].e);
    if (s > e){ puts("Game cheated!"); return 0; }
    lld cnt = 0, last = s - 1, v = 0;
    sort(A+1, A+N+1, [](const Z &a, const Z &b){
        return a.s < b.s;
    });
    for (int i=1;i<=N;i++) if (!A[i].t && A[i].s <= e){
        if (A[i].s > last+1) cnt += A[i].s - last - 1, v = last + 1, last = A[i].e;
        else last = max(last, A[i].e);
    }
    if (last < e) cnt += e - last, v = last + 1;
    if (!cnt) puts("Game cheated!");
    else if (cnt == 1) printf("%lld\n", v);
    else puts("Data not sufficient!");
}
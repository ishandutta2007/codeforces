#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

struct pos {
    int mn, mx;
    bool pos;
    int val;
};

int T;
int m;
int p[Maxn];

pos Solve(int l, int r)
{
    pos res;
    if (l == r) {
        res.mn = res.mx = p[l];
        res.pos = true;
        res.val = 0;
    } else {
        int m = l + r >> 1;
        pos A = Solve(l, m), B = Solve(m + 1, r);
        res.mn = min(A.mn, B.mn);
        res.mx = max(A.mx, B.mx);
        res.pos = A.pos && B.pos;
        res.val = A.val + B.val;
        if (A.mx < B.mn) return res;
        if (B.mx < A.mn) {
            res.val++;
            return res;
        }
        res.pos = false;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &p[i]);
        pos got = Solve(0, m - 1);
        printf("%d\n", got.pos? got.val: -1);
    }
    return 0;
}
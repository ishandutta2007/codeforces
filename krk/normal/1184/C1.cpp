#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50;
const int lim = 1000000000;

int n;
int X[Maxn], Y[Maxn];

bool onBoundary(int X1, int Y1, int X2, int Y2, int ind)
{
    return (X[ind] == X1 || X[ind] == X2) && Y1 <= Y[ind] && Y[ind] <= Y2 ||
           (Y[ind] == Y1 || Y[ind] == Y2) && X1 <= X[ind] && X[ind] <= X2;
}

int main()
{
    scanf("%d", &n);
    n = 4 * n + 1;
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++) {
        int mnx = lim, mxx = -lim;
        int mny = lim, mxy = -lim;
        for (int j = 0; j < n; j++) if (i != j) {
            mnx = min(mnx, X[j]);
            mxx = max(mxx, X[j]);
            mny = min(mny, Y[j]);
            mxy = max(mxy, Y[j]);
        }
        bool ok = mxy - mny == mxx - mnx && !onBoundary(mnx, mny, mxx, mxy, i);
        for (int j = 0; j < n && ok; j++) if (i != j)
            ok = onBoundary(mnx, mny, mxx, mxy, j);
        if (ok) { printf("%d %d\n", X[i], Y[i]); return 0; }
    }
    return 0;
}
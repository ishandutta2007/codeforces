#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;

int T;
int W, H;
int X1, Y1, X2, Y2;
int w, h;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &W, &H);
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        scanf("%d %d", &w, &h);
        int res = Inf;
        if (w + X2 - X1 <= W) {
            res = min(res, max(0, w - X1));
            res = min(res, max(0, X2 - (W - w)));
        }
        if (h + Y2 - Y1 <= H) {
            res = min(res, max(0, h - Y1));
            res = min(res, max(0, Y2 - (H - h)));
        }
        printf("%d\n", res == Inf? -1: res);
    }
    return 0;
}
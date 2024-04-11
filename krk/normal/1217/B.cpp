#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, x;
int mxd, mxdif;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        mxd = 0; mxdif = 0;
        for (int i = 0; i < n; i++) {
            int d, h; scanf("%d %d", &d, &h);
            mxd = max(mxd, d);
            mxdif = max(mxdif, d - h);
        }
        if (x <= mxd) printf("1\n");
        else if (mxdif == 0) printf("-1\n");
        else {
            x -= mxd;
            printf("%d\n", (x - 1) / mxdif + 2);
        }
    }
    return 0;
}
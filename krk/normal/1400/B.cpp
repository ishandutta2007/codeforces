#include <bits/stdc++.h>
using namespace std;

int T;
int p, f;
int cnts, cntw;
int s, w;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &p, &f);
        scanf("%d %d", &cnts, &cntw);
        scanf("%d %d", &s, &w);
        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }
        int res = 0;
        for (int i = 0; i <= cnts && i * s <= p; i++) {
            int lfts = cnts - i;
            int j = min((p - i * s) / w, cntw);
            int lftw = cntw - j;
            int c = min(f / s, lfts);
            int z = min((f - c * s) / w, lftw);
            res = max(res, i + j + c + z);
        }
        printf("%d\n", res);
    }
    return 0;
}
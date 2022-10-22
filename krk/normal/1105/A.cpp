#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int a[Maxn];
int bt = 0, best = 1000000000;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int t = 1; t <= 100; t++) {
        int cand = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < t) cand += t - a[i] - 1;
            else if (a[i] > t) cand += a[i] - t - 1;
        if (cand < best) {
            best = cand; bt = t;
        }
    }
    printf("%d %d\n", bt, best);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int t;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int best = 2000000000, bi = -1;
        for (int i = 0; i + k < n; i++) {
            int cand = (a[i + k] - a[i] + 1) / 2;
            if (cand < best) { best = cand; bi = a[i] + cand; }
        }
        printf("%d\n", bi);
    }
    return 0;
}
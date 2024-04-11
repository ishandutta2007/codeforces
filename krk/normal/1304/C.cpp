#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int Q;
int n, m;
int T[Maxn], L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d %d %d", &T[i], &L[i], &R[i]);
        int l = L[n - 1], r = R[n - 1];
        bool fal = false;
        for (int i = n - 2; i >= 0; i--) {
            int dif = T[i + 1] - T[i];
            l -= dif; r += dif;
            l = max(l, L[i]);
            r = min(r, R[i]);
            if (l > r) fal = true;
        }
        int dif = T[0];
        l -= dif; r += dif;
        if (m < l || r < m) fal = true;
        printf("%s\n", fal? "NO": "YES");
    }
    return 0;
}
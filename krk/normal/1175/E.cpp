#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 500005;
const int Maxm = 22;

int n, m;
int mx[Maxn];
int nxt[Maxn][Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        mx[a] = max(mx[a], b);
    }
    for (int i = 1; i < Maxn; i++) {
        if (!mx[i]) mx[i] = i;
        mx[i] = max(mx[i], mx[i - 1]);
    }
    for (int i = Maxn - 1; i >= 0; i--) {
        nxt[i][0] = mx[i];
        for (int j = 1; j < Maxm; j++)
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        if (nxt[l][Maxm - 1] < r) printf("-1\n");
        else {
            int res = 0;
            for (int i = Maxm - 1; i >= 0; i--)
                if (nxt[l][i] < r) {
                    res += 1 << i;
                    l = nxt[l][i];
                }
            res++;
            printf("%d\n", res);
        }
    }
    return 0;
}
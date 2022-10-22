#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Inf = 1000000000;

int T;
int n;
int seq[Maxn];

int Solve(int A, int B)
{
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int nd = Inf;
        for (int a = 0; a <= A && a <= seq[i]; a++)
            for (int b = 0; b <= B && a + 2 * b <= seq[i]; b++) {
                int lft = seq[i] - a - 2 * b;
                if (lft % 3) continue;
                nd = min(nd, lft / 3);
            }
        mx = max(mx, nd);
    }
    return mx;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &seq[i]);
        int res = Inf;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                res = min(res, Solve(i, j) + i + j);
        printf("%d\n", res);
    }
    return 0;
}
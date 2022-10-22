#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;
const int Maxm = 5;

int T;
int n;
int R[Maxn][Maxm];

bool Better(int a, int b)
{
    int res = 0;
    for (int j = 0; j < Maxm; j++)
        res += R[a][j] < R[b][j];
    return res >= 3;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < Maxm; j++)
                scanf("%d", &R[i][j]);
        int best = 0;
        for (int i = 1; i < n; i++)
            if (Better(i, best)) best = i;
        for (int i = 0; i < n && best != -1; i++) if (i != best)
            if (!Better(best, i)) best = -1;
        printf("%d\n", best == -1? -1: best + 1);
    }
    return 0;
}
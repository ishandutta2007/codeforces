#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Inf = 2000000007;

int T;
int m, n;
vector <vector <int> > B;
int best[Maxn], wh[Maxn];
int R[Maxn];

int Get(int a, int b)
{
    int res = -Inf;
    for (int i = 0; i < m; i++)
        res = max(res, min(B[i][a], B[i][b]));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; i++)
            best[i] = -Inf;
        B.resize(m);
        for (int i = 0; i < m; i++) {
            B[i].resize(n);
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
                if (B[i][j] > best[j]) {
                    best[j] = B[i][j];
                    wh[j] = i;
                }
            }
        }
        R[n] = Inf;
        for (int i = n - 1; i >= 0; i--)
            R[i] = min(best[i], R[i + 1]);
        if (m < n) printf("%d\n", R[0]);
        else {
            int res = -Inf;
            int L = Inf;
            for (int i = 0; i < n; i++) {
                int mid = Inf;
                for (int j = i + 1; j < n; j++) {
                    int mn = min(min(L, R[j + 1]), min(mid, Get(i, j)));
                    res = max(res, mn);
                    mid = min(mid, best[j]);
                }
                L = min(L, best[i]);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
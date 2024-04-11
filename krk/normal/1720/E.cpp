#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Maxm = Maxn * Maxn;
const int Inf = 1000000000;

int n, k;
int R1[Maxm], C1[Maxm], R2[Maxm], C2[Maxm];
int X;
vector <int> L[Maxn], R[Maxn];

bool Solve(int r, int c)
{
    for (int j = 0; j < n; j++) {
        L[j].clear();
        R[j].clear();
    }
    for (int i = 0; i < Maxm; i++) if (R1[i] != Inf)
        if (R1[i] >= r && C1[i] >= c) {
            int dist1 = min(R1[i] - r, C1[i] - c);
            int nd1 = c + dist1;
            int dist2 = max(R2[i] - r, C2[i] - c);
            int nd2 = c + dist2;
            if (r + dist2 >= n || c + dist2 >= n) continue;
            L[nd1].push_back(nd2);
            R[nd2].push_back(nd1);
        }
    int lef = c, cur = 0;
    for (int rig = c; rig < n; rig++) {
        for (int i = 0; i < R[rig].size(); i++)
            cur += int(R[rig][i] >= lef);
        while (cur > X + 1) {
            for (int i = 0; i < L[lef].size(); i++)
                cur -= int(L[lef][i] <= rig);
            lef++;
        }
        if (cur == X || cur == X + 1)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    fill(R1, R1 + Maxm, Inf);
    fill(C1, C1 + Maxm, Inf);
    fill(R2, R2 + Maxm, -Inf);
    fill(C2, C2 + Maxm, -Inf);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a; scanf("%d", &a);
            R1[a] = min(R1[a], i);
            R2[a] = max(R2[a], i);
            C1[a] = min(C1[a], j);
            C2[a] = max(C2[a], j);
        }
    int cur = 0;
    for (int i = 0; i < Maxm; i++)
        cur += int(R1[i] != Inf);
    if (k >= cur) { printf("%d\n", k - cur); return 0; }
    X = cur - k;
    for (int j = 0; j < n; j++)
        if (Solve(0, j)) { printf("1\n"); return 0; }
    for (int i = 1; i < n; i++)
        if (Solve(i, 0)) { printf("1\n"); return 0; }
    printf("2\n");
    return 0;
}
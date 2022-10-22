#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 3;

int T;
int n;
int R[Maxd], C[Maxd];
map <int, int> MR, MC;
bool col, row;
int bestrow, bestcol;
set <ii> S;

ii getCoords(ii p)
{
    if (row) p.first %= 2;
    if (col) p.second %= 2;
    return p;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        MR.clear(); MC.clear();
        for (int i = 0; i < Maxd; i++) {
            scanf("%d %d", &R[i], &C[i]);
            MR[R[i]]++;
            MC[C[i]]++;
        }
        col = MR.begin()->second > MR.rbegin()->second? bool(MR.begin()->first > 1): bool(MR.rbegin()->first < n);
        row = MC.begin()->second > MC.rbegin()->second? bool(MC.begin()->first > 1): bool(MC.rbegin()->first < n);
        if (col || row) col = row = true;
        bestrow = MR.begin()->second > MR.rbegin()->second? MR.begin()->first: MR.rbegin()->first;
        bestcol = MC.begin()->second > MC.rbegin()->second? MC.begin()->first: MC.rbegin()->first;
        if (col) bestcol %= 2;
        if (row) bestrow %= 2;
        S.clear();
        for (int i = 0; i < Maxd; i++)
            S.insert(getCoords(ii(R[i], C[i])));
        int x, y; scanf("%d %d", &x, &y);
        auto p = getCoords(ii(x, y));
        if (S.count(p) || p.first == bestrow || p.second == bestcol) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
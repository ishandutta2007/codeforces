#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 4;

int T;
int w, h;
vector <int> V[Maxd];

ll Solve(int my, int oth, int dif, int a, int b, bool fr)
{
    if (V[my].empty()) return 0;
    ll A = V[my].back() - V[my][0];
    if (!V[oth].empty()) return ll(dif) * A;
    if (fr) {
        ll res = 0ll;
        if (!V[a].empty()) res = max(res, ll(dif - V[a][0]) * A);
        if (!V[b].empty()) res = max(res, ll(dif - V[b][0]) * A);
        return res;
    }
    ll res = 0ll;
    if (!V[a].empty()) res = max(res, ll(V[a].back()) * A);
    if (!V[b].empty()) res = max(res, ll(V[b].back()) * A);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &w, &h);
        for (int i = 0; i < Maxd; i++) {
            int c; scanf("%d", &c);
            V[i].resize(c);
            for (int j = 0; j < c; j++)
                scanf("%d", &V[i][j]);
        }
        ll res = Solve(0, 1, h, 2, 3, false);
        res = max(res, Solve(1, 0, h, 2, 3, true));
        res = max(res, Solve(2, 3, w, 0, 1, false));
        res = max(res, Solve(3, 2, w, 0, 1, true));
        printf("%I64d\n", res);
    }
    return 0;
}
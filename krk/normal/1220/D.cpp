#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 62;
const int Maxn = 200005;

int n;
ll B[Maxn];
vector <ll> V[Maxb];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll b; scanf("%I64d", &b);
        B[i] = b;
        int j = 0;
        while (!(b & 1ll << ll(j))) j++;
        V[j].push_back(b);
    }
    if (n == 1) { printf("0\n"); return 0; }
    int mx = 0;
    for (int j = 0; j < Maxb; j++)
        if (V[j].size() > V[mx].size()) mx = j;
    int best = n - int(V[mx].size());
    printf("%d\n", best);
    for (int i = 0; i < Maxb; i++) if (i != mx)
        for (int j = 0; j < V[i].size(); j++)
            printf("%I64d ", V[i][j]);
    printf("\n");
    return 0;
}
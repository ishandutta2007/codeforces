#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1005;
const int Maxd = 5;

int n;
int res[Maxn];
int st;

int Ask(int a, int b, int c)
{
    printf("? %d %d %d\n", st + a, st + b, st + c);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Print()
{
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %d", res[i]);
    printf("\n");
    fflush(stdout);
}

void Solve()
{
    vector <ii> seq;
    map <int, int> M;
    for (int i = 0; i < Maxd; i++)
        for (int j = i + 1; j < Maxd; j++)
            for (int k = j + 1; k < Maxd; k++) {
                int mask = (1 << i | 1 << j | 1 << k);
                int got = Ask(i, j, k);
                seq.push_back(ii(got, mask));
                M[mask] = got;
            }
    sort(seq.begin(), seq.end());
    ii mask1 = ii(-1, -1), mask2 = ii(-1, -1);
    for (int i = 0; i < seq.size() && mask1.second == -1; i++) if (seq[i].first == seq[0].first)
        for (int j = i + 1; j < seq.size() && mask2.second == -1; j++) if (seq[j].first == seq.back().first)
            if (__builtin_popcount(seq[i].second & seq[j].second) == 1 &&
                __builtin_popcount(seq[i].second | seq[j].second) == Maxd) {
                mask1 = seq[i];
                mask2 = seq[j];
            }
    int c = __builtin_popcount((mask1.second & mask2.second) - 1);
    int best = 2000000007, a, d;
    for (int i = 0; i < Maxd; i++) if (i != c && bool(mask1.second & 1 << i))
        for (int j = 0; j < Maxd; j++) if (j != c && bool(mask2.second & 1 << j)) {
            int cand = M[1 << i | 1 << c | 1 << j];
            if (cand < best) { best = cand; a = i; d = j; }
        }
    int b = __builtin_popcount((mask1.second ^ 1 << a ^ 1 << c) - 1);
    int e = __builtin_popcount((mask2.second ^ 1 << d ^ 1 << c) - 1);
    int x1 = M[1 << a | 1 << c | 1 << d];
    int x2 = M[1 << a | 1 << c | 1 << e];
    int x3 = M[1 << b | 1 << c | 1 << d];
    int x4 = M[1 << b | 1 << c | 1 << e];
    int x5 = M[1 << a | 1 << b | 1 << c];
    int x6 = M[1 << c | 1 << d | 1 << e];
    int cval = (ll(x5) + ll(x6) - ll(x2)) / 2;
    int aval = x5 - cval;
    int eval = x6 - cval;
    int dval = x1 - aval;
    int bval = x4 - eval;
    res[st + a] = aval;
    res[st + b] = bval;
    res[st + c] = cval;
    res[st + d] = dval;
    res[st + e] = eval;
}

int main()
{
    scanf("%d", &n);
    for (st = 1; st + Maxd <= n + 1; st += Maxd)
        Solve();
    if (n % 5) {
        st = n - Maxd + 1;
        Solve();
    }
    Print();
    return 0;
}
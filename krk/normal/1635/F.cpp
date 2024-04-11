#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const ll Inf = 9000000000000000000ll;

int n, q;
int X[Maxn], W[Maxn];
vector <int> S;
ll BIT[Maxn];
vector <ii> quer[Maxn];
ll res[Maxn];

void Insert(int ind, ll x)
{
    for (int i = ind; i > 0; i -= i & -i)
        BIT[i] = min(BIT[i], x);
}

ll Get(int ind)
{
    ll res = Inf;
    for (int i = ind; i < Maxn; i += i & -i)
        res = min(res, BIT[i]);
    return res;
}

int main()
{
    fill(BIT, BIT + Maxn, Inf);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &X[i], &W[i]);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        quer[r].push_back(ii(l, i));
    }
    for (int i = 1; i <= n; i++) {
        while (!S.empty() && W[S.back()] >= W[i]) {
            Insert(S.back(), ll(X[i] - X[S.back()]) * (W[S.back()] + W[i]));
            S.pop_back();
        }
        if (!S.empty())
            Insert(S.back(), ll(X[i] - X[S.back()]) * (W[S.back()] + W[i]));
        S.push_back(i);
        for (int j = 0; j < quer[i].size(); j++) {
            ii p = quer[i][j];
            res[p.second] = Get(p.first);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%I64d\n", res[i]);
    return 0;
}
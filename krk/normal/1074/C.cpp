#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;
const int Inf = 1000000000;

int n;
int X[Maxn], Y[Maxn];
ll res;
vector <int> seq;
ll best[Maxn];

ll getPer(int a, int b, int c)
{
    int mnx = min(min(X[a], X[b]), X[c]);
    int mxx = max(max(X[a], X[b]), X[c]);
    int mny = min(min(Y[a], Y[b]), Y[c]);
    int mxy = max(max(Y[a], Y[b]), Y[c]);
    return 2ll * (ll(mxy - mny) + ll(mxx - mnx));
}

int main()
{
    scanf("%d", &n);
    int mnx = Inf, mxx = -Inf;
    int mny = Inf, mxy = -Inf;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        mnx = min(mnx, X[i]);
        mxx = max(mxx, X[i]);
        mny = min(mny, Y[i]);
        mxy = max(mxy, Y[i]);
    }
    vector <int> V;
    for (int i = 0; i < n; i++)
        if (X[i] == mnx || X[i] == mxx ||
            Y[i] == mny || Y[i] == mxy)
            V.push_back(i);
    for (int i = 0; i <= V.size(); i++)
        best[i] = 0;
    for (int i = 0; i < 1 << V.size(); i++) {
        mnx = Inf, mxx = -Inf;
        mny = Inf, mxy = -Inf;
        int bits = 0;
        for (int j = 0; j < V.size(); j++) if (i & 1 << j) {
            bits++;
            mnx = min(mnx, X[V[j]]);
            mxx = max(mxx, X[V[j]]);
            mny = min(mny, Y[V[j]]);
            mxy = max(mxy, Y[V[j]]);
        }
        best[bits] = max(best[bits], 2ll * (ll(mxy - mny) + ll(mxx - mnx)));
    }
    for (int i = 0; i < V.size(); i++)
        for (int j = i + 1; j < V.size(); j++)
            for (int k = 0; k < n; k++)
                best[3] = max(best[3], getPer(V[i], V[j], k));
    for (int i = 3; i <= n; i++) {
        ll val = i > V.size()? best[V.size()]: best[i];
        printf("%I64d%c", val, i + 1 <= n? ' ': '\n');
    }
    return 0;
}
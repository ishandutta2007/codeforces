#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 2005;

int n;
int X[Maxn], Y[Maxn];
int par[Maxn], siz[Maxn];
int K[Maxn];
vector <llii> E;
ll tot;
vector <int> A;
vector <ii> B;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d", &n);
    par[0] = 0; siz[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        par[i] = i; siz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int c; scanf("%d", &c);
        E.push_back(llii(c, ii(0, i)));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &K[i]);
        for (int j = 1; j < i; j++) {
            ll cost = ll(abs(X[j] - X[i]) + abs(Y[j] - Y[i])) * ll(K[j] + K[i]);
            E.push_back(llii(cost, ii(j, i)));
        }
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++) {
        int a = E[i].second.first, b = E[i].second.second;
        if (unionSet(a, b)) {
            tot += E[i].first;
            if (a == 0) A.push_back(b);
            else B.push_back(ii(a, b));
        }
    }
    printf("%I64d\n", tot);
    printf("%d\n", int(A.size()));
    for (int i = 0; i < A.size(); i++)
        printf("%d%c", A[i], i + 1 < A.size()? ' ': '\n');
    printf("%d\n", int(B.size()));
    for (int i = 0; i < B.size(); i++)
        printf("%d %d\n", B[i].first, B[i].second);
    return 0;
}
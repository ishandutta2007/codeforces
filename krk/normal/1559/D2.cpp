#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m1, m2;
int par[2][Maxn], siz[2][Maxn];

int getPar(int t, int x) { return par[t][x] == x? x: par[t][x] = getPar(t, par[t][x]); }

bool unionSet(int t, int a, int b)
{
    a = getPar(t, a), b = getPar(t, b);
    if (a == b) return false;
    if (siz[t][a] < siz[t][b]) swap(a, b);
    siz[t][a] += siz[t][b];
    par[t][b] = a;
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++) {
        par[0][i] = par[1][i] = i;
        siz[0][i] = siz[1][i] = 1;
    }
    for (int i = 0; i < m1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(0, a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(1, a, b);
    }
    vector <ii> res;
    for (int j = 2; j <= n; j++)
        if (getPar(0, 1) != getPar(0, j) && getPar(1, 1) != getPar(1, j)) {
            unionSet(0, 1, j);
            unionSet(1, 1, j);
            res.push_back(ii(1, j));
        }
    vector <int> A, B;
    for (int i = 2; i <= n; i++)
        if (getPar(0, i) == getPar(0, 1) && getPar(1, i) != getPar(1, 1))
            A.push_back(i);
        else if (getPar(0, i) != getPar(0, 1) && getPar(1, i) == getPar(1, 1))
            B.push_back(i);
    while (A.size() && B.size())
        if (!(getPar(0, A.back()) == getPar(0, 1) && getPar(1, A.back()) != getPar(1, 1))) A.pop_back();
        else if (!(getPar(0, B.back()) != getPar(0, 1) && getPar(1, B.back()) == getPar(1, 1))) B.pop_back();
        else {
            unionSet(0, A.back(), B.back());
            unionSet(1, A.back(), B.back());
            res.push_back(ii(A.back(), B.back()));
        }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
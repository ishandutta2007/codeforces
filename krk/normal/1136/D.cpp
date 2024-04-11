#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n, m;
int p[Maxn];
int st;
set <ii> S;

void Solve(int ind)
{
    while (true) {
        while (st < ind && S.find(ii(p[ind - 1], p[ind])) != S.end()) {
            swap(p[ind - 1], p[ind]);
            ind--;
        }
        if (st == ind) { st++; return; }
        Solve(ind - 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    int me = p[n - 1];
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        S.insert(ii(a, b));
    }
    Solve(n - 1);
    int pnt = 0;
    while (p[pnt] != me) pnt++;
    printf("%d\n", n - 1 - pnt);
    return 0;
}
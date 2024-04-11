#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;

int mx[Maxn];
int par[Maxn], siz[Maxn];
int n, q;
int a[Maxn];
set <ii> S;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
}

void Add(int a, int b)
{
    if (a > b) swap(a, b);
    S.insert(ii(a, b));
}

bool Check(int a, int b)
{
    if (a > b) swap(a, b);
    return S.find(ii(a, b)) != S.end();
}

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0) {
        par[i] = i;
        siz[i] = 1;
        for (int j = i; j < Maxn; j += i)
            mx[j] = i;
    }
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (siz[a[i]] > 0) continue;
        par[a[i]] = a[i];
        siz[a[i]] = 1;
        int num = a[i];
        while (num > 1) {
            int cur = mx[num];
            unionSet(a[i], cur);
            while (mx[num] == cur) num /= cur;
        }
    }
    for (int i = 0; i < n; i++) {
        set <int> myS;
        myS.insert(getPar(a[i]));
        int num = a[i] + 1;
        while (num > 1) {
            int cur = mx[num];
            myS.insert(getPar(cur));
            while (mx[num] == cur) num /= cur;
        }
        for (auto it = myS.begin(); it != myS.end(); it++)
            for (auto it2 = it; it2 != myS.end(); it2++) if (*it != *it2)
                Add(*it, *it2);
    }
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        u = getPar(a[u - 1]), v = getPar(a[v - 1]);
        if (u == v) printf("0\n");
        else if (Check(u, v)) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
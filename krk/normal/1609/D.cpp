#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, d;
int par[Maxn], siz[Maxn];

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
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    int add = 0;
    for (int i = 0; i < d; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (!unionSet(a, b)) add++;
        vector <int> seq;
        for (int j = 1; j <= n; j++)
            if (getPar(j) == j) seq.push_back(siz[j]);
        sort(seq.rbegin(), seq.rend());
        int my = 0;
        for (int j = 0; j <= add && j < seq.size(); j++)
            my += seq[j];
        printf("%d\n", my - 1);
    }
    return 0;
}
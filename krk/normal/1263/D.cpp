#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;
const int MaxL = 1000005;

char tmp[MaxL];
int n;
string s[Maxn];
int par[Maxn], siz[Maxn];
int has[Maxl];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
}

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Read(s[i]);
        par[i] = i; siz[i] = 1;
        for (int j = 0; j < s[i].length(); j++) {
            int let = s[i][j] - 'a';
            if (has[let]) unionSet(has[let], i);
            has[let] = i;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (getPar(i) == i) res++;
    printf("%d\n", res);
    return 0;
}
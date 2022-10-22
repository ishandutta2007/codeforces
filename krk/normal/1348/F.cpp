#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

ii st[Maxm];
int n;
int a[Maxn], b[Maxn];
vector <ii> add[Maxn];
priority_queue <ii> Q;
int res[Maxn], inres[Maxn];

void setMax(int v, int l, int r, int x, int val)
{
    st[v] = max(st[v], ii(val, x));
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) setMax(2 * v, l, m, x, val);
        else setMax(2 * v + 1, m + 1, r, x, val);
    }
}

ii Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        ii res = ii(0, 0);
        if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

void Print()
{
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        add[a[i]].push_back(ii(-b[i], i));
    }
    int sa = -1, sb = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < add[i].size(); j++)
            Q.push(add[i][j]);
        int ind = Q.top().second; Q.pop();
        ii my = Get(1, 1, n, a[ind], b[ind]);
        if (my.first >= i) { sa = my.second; sb = i; }
        res[ind] = i; inres[i] = ind;
        setMax(1, 1, n, i, b[ind]);
    }
    if (sa != -1) {
        printf("NO\n");
        Print();
        swap(res[inres[sa]], res[inres[sb]]);
        Print();
        return 0;
    }
    printf("YES\n");
    Print();
    return 0;
}
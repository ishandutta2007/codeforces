#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 600005;
const int Maxm = 4194304;

int n, r;
int X[Maxn], Y[Maxn];
vector <iii> seq;
vector <int> un;
int st[Maxm], fl[Maxm];
int res;

void downOn(int v, int f)
{
    st[v] += f;
    fl[v] += f;
}

void Down(int v)
{
    if (fl[v]) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = 0;
    }
}

void Union(int v)
{
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void Update(int v, int l, int r, int a, int b, int val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &r); r *= 2;
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        X[i] = x + y; Y[i] = x - y;
        seq.push_back(iii(ii(X[i], 0), i));
        seq.push_back(iii(ii(X[i] + r, 1), i));
        un.push_back(Y[i] - r);
        un.push_back(Y[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++) {
        int ind = seq[i].second;
        int delt = seq[i].first.second == 0? 1: -1;
        int lef = lower_bound(un.begin(), un.end(), Y[ind] - r) - un.begin();
        int rig = lower_bound(un.begin(), un.end(), Y[ind]) - un.begin();
        Update(1, 0, int(un.size()) - 1, lef, rig, delt);
        res = max(res, st[1]);
    }
    printf("%d\n", res);
    return 0;
}
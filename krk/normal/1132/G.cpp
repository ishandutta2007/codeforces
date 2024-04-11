#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 4194304;

int n, k;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int st[Maxm], flag[Maxm];

void Traverse(int v)
{
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
    rig[v] = cur;
}

void downOn(int v, int f)
{
    st[v] += f; flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
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
        int m = l + r >> 1;
        Down(v);
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    vector <ii> S;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        while (!S.empty() && S.back().first < a) {
            neigh[i].push_back(S.back().second);
            S.pop_back();
        }
        S.push_back(ii(a, i));
    }
    for (int i = n; i > 0; i--) if (!lef[i])
        Traverse(i);
    for (int i = 1; i < k; i++)
        Update(1, 1, n, lef[i], rig[i], 1);
    for (int i = k; i <= n; i++) {
        Update(1, 1, n, lef[i], rig[i], 1);
        printf("%d%c", st[1], i + 1 <= n? ' ': '\n');
        Update(1, 1, n, lef[i - (k - 1)], rig[i - (k - 1)], -1);
    }
    return 0;
}
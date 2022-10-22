#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 1000000000;

int st[2][Maxm];
bool fl[2][Maxm];
int n;
int p[Maxn];
int in[Maxn], de[Maxn];
ll res;

void downOn(int t, int v)
{
    st[t][v] = -Inf;
    fl[t][v] = true;
}

void Down(int t, int v)
{
    if (fl[t][v]) {
        downOn(t, 2 * v);
        downOn(t, 2 * v + 1);
        fl[t][v] = false;
    }
}

void Union(int t, int v)
{
    st[t][v] = max(st[t][2 * v], st[t][2 * v + 1]);
}

void Clear(int t) { downOn(t, 1); }

void Update(int t, int v, int l, int r, int x, int val)
{
    if (l == r) st[t][v] = max(st[t][v], val);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (x <= m) Update(t, 2 * v, l, m, x, val);
        else Update(t, 2 * v + 1, m + 1, r, x, val);
        Union(t, v);
    }
}

int Get(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[t][v];
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (b <= m) return Get(t, 2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(t, 2 * v + 1, m + 1, r, a, b);
        return max(Get(t, 2 * v, l, m, a, m), Get(t, 2 * v + 1, m + 1, r, m + 1, b));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int incrig, decrig;
    for (int i = n; i >= 1; i--) {
        if (i == n || p[i] > p[i + 1]) {
            Clear(0);
            incrig = i + 1;
        }
        if (i == n)
            Update(0, 1, 0, Maxn, 0, n + 1);
        else Update(0, 1, 0, Maxn, p[i + 1], de[i + 1]);
        if (i == n || p[i] < p[i + 1]) {
            Clear(1);
            decrig = i + 1;
        }
        if (i == n)
            Update(1, 1, 0, Maxn, Maxn, n + 1);
        else Update(1, 1, 0, Maxn, p[i + 1], in[i + 1]);
        int rig = max(max(incrig, decrig), max(st[0][1], st[1][1]));
        res += rig - i;
        if (i > 1) {
            in[i] = max(incrig, Get(0, 1, 0, Maxn, 0, p[i - 1]));
            de[i] = max(decrig, Get(1, 1, 0, Maxn, p[i - 1], Maxn));
        }
    }
    cout << res << endl;
    return 0;
}
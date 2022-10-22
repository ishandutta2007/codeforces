#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 4194304;

int pnt;
int n;
char str[Maxn];
int A, B;
string lin(Maxn, '?');
int mn[Maxm], mx[Maxm];
int flag[Maxm];

void downOn(int v, int f)
{
    mn[v] += f; mx[v] += f;
    flag[v] += f;
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
    mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
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
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') pnt = max(0, pnt - 1);
        else if (str[i] == 'R') pnt++;
        else if (str[i] != lin[pnt]) {
            if (str[i] == '(') {
                A++;
                if (lin[pnt] == ')') { B--; Update(1, 0, Maxn - 1, pnt, Maxn - 1, 2); }
                else Update(1, 0, Maxn - 1, pnt, Maxn - 1, 1);
            } else if (str[i] == ')') {
                B++;
                if (lin[pnt] == '(') { A--; Update(1, 0, Maxn - 1, pnt, Maxn - 1, -2); }
                else Update(1, 0, Maxn - 1, pnt, Maxn - 1, -1);
            } else if (lin[pnt] == ')') { B--; Update(1, 0, Maxn - 1, pnt, Maxn - 1, 1); }
              else if (lin[pnt] == '(') { A--; Update(1, 0, Maxn - 1, pnt, Maxn - 1, -1); }
            lin[pnt] = str[i];
        }
        int res = -1;
        if (A == B && mn[1] == 0) res = mx[1];
        printf("%d%c", res, i + 1 < n? ' ': '\n');
    }
    return 0;
}
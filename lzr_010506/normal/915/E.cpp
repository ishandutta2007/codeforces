#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
//#define ls rt << 1
//#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;

int n, q;
int sum[300010*50], ls[300010*50], rs[300010*50], op[300010*50];
int tot = 1;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
void push_up(int rt)
{
    sum[rt] = sum[ls[rt]]+sum[rs[rt]];
}
void allset(int rt, int len, int v) 
{
    if (v == 0) sum[rt] = 0, op[rt] = 1;
    else sum[rt] = len, op[rt] = 2;
}
void push_down(int rt, int l, int r)
{
    if (op[rt])
    {
        int m = (l+r)>>1;
        if (!ls[rt]) ls[rt] = ++tot;
        if (!rs[rt]) rs[rt] = ++tot;
        allset(ls[rt], m-l+1, op[rt]-1);
        allset(rs[rt], r-m, op[rt]-1);
        op[rt] = 0;
    }
}
void Update(int L, int R, int opt, int l, int r, int rt)
{
    if (L <= l && r <= R) 
    {
        allset(rt, r-l+1, opt);
        return;
    }
    push_down(rt, l, r);
    int m = (l + r) >> 1;
    if (L <= m)
    {
        if (!ls[rt]) ls[rt] = ++tot;
        Update(L, R, opt, l, m, ls[rt]);
    }
    if (R > m)
    {
        if (!rs[rt]) rs[rt] = ++tot;
        Update(L, R, opt, m+1, r, rs[rt]);
    }
    push_up(rt);
}
int l, r, k;
int main()
{
    n = read(), q = read();
    while (q--)
    {
        l = read(), r = read(), k = read();
        Update(l, r, 2-k, 1, n, 1);
        printf("%d\n", n-sum[1]);
    }
    return 0;
}
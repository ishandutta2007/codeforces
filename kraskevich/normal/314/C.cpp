#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000 + 10;
int t[4 * N];
int n;

void build(int i, int l, int r)
{
    t[i] = (l == 0 ? 1 : 0);
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    t[i] = t[2 * i + 1] + t[2 * i + 2];
}

int get(int i, int l, int r, int tl, int tr)
{
    if (l == tl && r == tr)
        return t[i];
    int sl = 0;
    int sr = 0;
    int m = (tl + tr) / 2;
    if (l <= m)
        sl = get(2 * i + 1, l, min(r, m), tl, m);
    if (r > m)
        sr = get(2 * i + 2, max(m + 1, l), r, m + 1, tr);
    return (sl + sr) % MOD;
}

void put(int i, int pos, int tl, int tr, int v)
{
    if (tl == pos && tr == pos)
    {
        t[i] = v;
        return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
        put(2 * i + 1, pos, tl, m, v);
    else
        put(2 * i + 2, pos, m + 1, tr, v);
    t[i] = (t[2 * i + 1] + t[2 * i + 2]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    build(0, 0, N - 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        long long pref = get(0, 0, x, 0, N - 1);
        pref = pref * x;
        pref %= MOD;
        put(0, x, 0, N - 1, pref);
    }

    cout << get(0, 1, N - 1, 0, N - 1);

    return 0;
}
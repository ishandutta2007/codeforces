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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 300 * 1000;
long long dy[N];
int finPos[N];
int was[N];
long long a[N];
int n;

void dfs(int x)
{
    if (was[x] > 0)
        return;

    was[x] = 1;

    int startX = x;
    dy[startX] = a[x];
    x += a[x];

    if (x <= 0 || x > n)
    {
        finPos[startX] = startX;
        was[startX] = 2;
        return;
    }

    dy[startX] += a[x];
    x -= a[x];
    if (x <= 0 || x > n)
    {
        finPos[startX] = startX;
    }
    else
    {
        if (x == 1 || was[x] == 1)
        {
            finPos[startX] = 1;
        }
        else
        {
            dfs(x);
            dy[startX] += dy[x];
            finPos[startX] = finPos[x];
        }
    }
    was[startX] = 2;
}

long long get_ans()
{
    long long x = 1;
    long long d = 0;
    d += a[x];
    x += a[x];
    if (x <= 0 || x > n)
        return d;
    d += a[x];
    x -= a[x];
    if (x <= 0 || x > n)
        return d;
    else
        return ((x == 1 || finPos[x] == 1) ? -1 : d + dy[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 2; i <= n; ++i)
        cin >> a[i];

    fill(was + 1, was + n + 1, 0);
    for (int i = 2; i <= n; ++i)
        if (!was[i])
            dfs(i);

    for (int i = 1; i <= n - 1; i++)
    {
        a[1] = i;
        cout << get_ans() << "\n";
    }

    return 0;
}
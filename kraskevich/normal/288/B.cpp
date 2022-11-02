#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

void openFiles()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const long long mod = 1000 * 1000 * 1000 + 7;
const int N = 1000 + 10;
int p[N];
int n, k;
bool used[N];
bool ok;
long long res = 0;

void dfs(int v)
{
    used[v] = true;
    int to = p[v];
    if (to == 0)
        ok = true;
    if (!used[to])
        dfs(to);
}

bool good()
{
    for (int i = 0; i < k; ++i)
    {
        fill(used, used + k, 0);
        ok = false;
        dfs(i);
        if (!ok)
            return false;
    }
    return true;
}

void work(int pos)
{
    if (pos == k)
    {
        if (good())
            res++;
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        p[pos] = i;
        work(pos + 1);
    }
}

void solve()
{
    cin >> n >> k;
    work(0);
    for (int i = 1; i <= n - k; ++i)
        res = (res * (n - k)) % mod;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}
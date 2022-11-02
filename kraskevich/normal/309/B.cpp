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
#include <sstream>

using namespace std;

const int N = 5000 * 1000 + 5;
string s[N];
int n, r, c;
int sum[N];
int dp[N];
bool u[N];
int p[N];
vector<int> at_h[N];
vector<int> g[N];

void dfs(int v, int h)
{
    u[v] = true;
    at_h[h].push_back(v);
    int lo = h - r;
    if (lo < 0)
        lo = 0;
    dp[v] = at_h[lo].back();
    for (int to: g[v])
        if (!u[to])
            dfs(to, h + 1);
    at_h[h].pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> r >> c;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        sum[i] = s[i].length();
        if (i)
            sum[i] += sum[i - 1];
    }

    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        ptr = max(ptr, i);
        for (;;)
        {
            int m = ptr + 1;
            if (m > n)
                break;
            int len = sum[m - 1] - (i ? sum[i - 1] : 0) + m - 1 - i;
            if (len > c)
                break;
            ptr++;
        }
        if (i == ptr)
            continue;
        g[ptr].push_back(i);
        p[i] = ptr;
    }

    for (int i = 0; i < n; i++)
        dp[i] = i;
    fill(u, u + N, 0);
    for (int i = n; i >= 0; i--)
        if (!u[i])
            dfs(i, 0);

    int ans = 0;
    int st = 0;
    int en = 0;

    for (int i = 0; i < n; i++)
    {
        int a = i;
        int b = dp[i];
        if (b - a > ans)
        {
            ans = b - a;
            st = a;
            en = b;
        }
    }

    for (int i = st; i != en; i = p[i])
    {
        int hi = p[i];
        for (int j = i; j < hi; j++)
        {
            cout << s[j];
            if (j != hi - 1)
                cout << " ";
        }
        if (p[i] != en)
            cout << "\n";
    }

    return 0;
}
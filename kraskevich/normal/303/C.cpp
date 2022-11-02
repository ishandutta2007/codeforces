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

const int N = 1000 * 1000 + 10;
int a[5555];
int n, k;
int cnt[N];
int bad[N];
int mx;
vector<pii> pre[N];
vector<pii> e[N];
vector<int> g[100];
int sz = 0;
bool u[100];

void dfs(int v)
{
    sz++;
    u[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!u[to])
            dfs(to);
    }
}

bool check(int x)
{
    map<int, int> s;
    int cnt = 0;
    for (int i = 0; i < e[x].size(); i++)
    {
        if (!s.count(e[x][i].F))
            s[e[x][i].F] = cnt++;
        if (!s.count(e[x][i].S))
            s[e[x][i].S] = cnt++;
    }
    for (int i = 0; i < cnt; i++)
    {
        u[i] = false;
        g[i].clear();
    }
    for (int i = 0; i < e[x].size(); i++)
    {
        int a = s[e[x][i].F];
        int b = s[e[x][i].S];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int tot = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (!u[i])
        {
            sz = 0;
            dfs(i);
            tot += sz - 1;
        }
    }
    return tot <= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fill(cnt, cnt + N, 0);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            cnt[a[j] - a[i]]++;
    fill(bad, bad + N, 0);
    for (int i = 1; i < N; i++)
        for (int x = i; x < N; x += i)
            bad[i] += cnt[x];
    mx = k * (k + 1) / 2;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (cnt[a[j] - a[i]] > mx)
                continue;
            pre[a[j] - a[i]].push_back(pii(i, j));
        }
    for (int i = 1; i < N; i++)
    {
        if (bad[i] > mx)
            continue;
        for (int x = i; x < N; x += i)
            for (pii val: pre[x])
                e[i].push_back(val);
        if (check(i))
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}
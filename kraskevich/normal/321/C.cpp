#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
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

#define PII pair<int, int>
#define F first
#define S second


const int N = 100 * 1000 + 10;

vector<int> g[N];
vector<int> gr[N];
vector<int> f;
int bad[N];
int u[N], mx[N], dp[N];
int n, tot;
char res[N];

void dfs(int v)
{
    f.push_back(v);
    u[v] = true;
    dp[v] = 1;
    mx[v] = 0;
    for (auto &to: g[v])
        if (!u[to])
        {
            dfs(to);
            dp[v] += dp[to];
            mx[v] = max(mx[v], dp[to]);
        }
}

void work(char ch)
{
    fill(u, u + n, 0);
    fill(bad, bad + n, 0);
    for (int i = 0; i < n; i++)
        gr[i].clear();
    for (int i = 0; i < n; i++)
    {
        if (u[i] || res[i])
            continue;
        f.clear();
        dfs(i);
        int sz = f.size();
        int x = 0;
        for (auto &v: f)
            if (2 * mx[v] <= sz && dp[v] * 2 >= sz)
                x = v;
        res[x] = ch;
        tot++;
        bad[x] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (bad[i])
            continue;
        for (auto &to: g[i])
            if (!bad[to])
                gr[i].push_back(to);
    }
    for (int i = 0; i < n; i++)
        g[i] = gr[i];
    if (tot == n)
        return;
    work(ch + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tot = 0;
    fill(res, res + n, 0);
    work('A');
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";


    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int M1 = 1e9 + 7, M2 = 934260073;

int t, n, ip, ic, f[2][1000005], sz, ans = 0;
bool vis[1000005];
char s[1000005];
pair<long long, long long> cur, par, rem;
vector<pair<long long, long long>> node;
vector<pair<pair<long long, long long>, pair<long long, long long>>> ed;
vector<int> adj[1000005];

int it(pair<long long, long long> a)
{
    return lower_bound(node.begin(), node.end(), a) - node.begin();
}

void DFS(int u)
{
    for (int v : adj[u])
    {
        DFS(v);
        f[0][u] += max(f[0][v], f[1][v]);
        f[1][u] += f[0][v];
    }
    adj[u].clear();
}

int main()
{
    //freopen("SIMIWORD.inp", "r", stdin);
    //freopen("SIMIWORD.out", "w", stdout);
    scanf("%d\n", &t);
    while (t--)
    {
        ans = 0;
        node.clear();
        scanf("%d\n", &n);
        while (n--)
        {
            scanf("%s\n", s);
            sz = strlen(s);
            cur = rem = make_pair(s[0] - 'a' + 1, s[0] - 'a' + 1);
            node.push_back(cur);
            for (int j = 1; j < sz; j++)
            {
                ((cur.first *= 31) += s[j] - 'a' + 1) %= M1;
                ((cur.second *= 47) += s[j] - 'a' + 1) %= M2;
                (rem.first *= 31) %= M1;
                (rem.second *= 47) %= M2;
                par.first = (cur.first - rem.first + M1) % M1;
                par.second = (cur.second - rem.second + M2) % M2;
                node.push_back(cur);
                ed.push_back(make_pair(par, cur));
            }
        }
        sort(node.begin(), node.end());
        node.resize(unique(node.begin(), node.end()) - node.begin());
        n = node.size();
        fill(vis, vis + n, false);
        fill(f[0], f[0] + n, 0);
        fill(f[1], f[1] + n, 1);
        for (; !ed.empty(); ed.pop_back())
            if (binary_search(node.begin(), node.end(), ed.back().first) && !vis[it(ed.back().second)])
            {
                adj[it(ed.back().first)].push_back(it(ed.back().second));
                vis[it(ed.back().second)] = true;
            }
        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                DFS(i);
                ans += max(f[0][i], f[1][i]);
            }
        printf("%d\n", ans);
    }
}
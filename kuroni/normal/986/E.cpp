#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 100005, Q = 100005, MX = 1E7 + 5, PR = 670000, MOD = 1E9 + 7;

vector<int> pro, sav, adj[N];
vector<pair<int, int>> val[PR];
int n, q, u, v, x, pr = 0, cnt = 0, cur = 1, a[N], h[N], rt[N], par[N], col[N], sub[N], in[N], d[MX], pos[MX];
long long ans[Q];

class CBIT
{
  private:
    int bit[N];

  public:
    void build()
    {
        fill(bit, bit + N, 0);
    }

    void upd(int u, int v)
    {
        for (; u <= n; u += u & -u)
            bit[u] += v;
    }
    
    int que(int u)
    {
        int ret = 0;
        for (; u > 0; u -= u & -u)
            ret += bit[u];
        return ret;
    }

    int que(int l, int r)
    {
        return que(r) - que(l - 1);
    }
} sum, chk;

struct SQuery
{
    int u, v, x, ind;
};
vector<SQuery> que[PR];

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 31 - __builtin_clz(p); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

void init()
{
    sum.build();
    chk.build();
    h[0] = -1;
    for (int i = 2; i < MX; i++)
        if (d[i] == 0)
        {
            sav.push_back(i);
            pos[i] = ++pr;
            d[i] = i;
            for (int j = i; j < MX / i; j++)
                d[i * j] = i;
        }
}

int DFS(int u, int p = 0)
{
    h[u] = h[p] + 1;
    par[u] = p;
    sub[u] = 1;
    for (int &v : adj[u])
        if (v != p)
            sub[u] += DFS(v, u);
    return sub[u];
}

void HLD(int u, int p = 0)
{
    in[u] = ++cnt;
    col[u] = cur;
    if (rt[cur] == 0)
        rt[cur] = u;
    int mc = 0;
    for (int &v : adj[u])
        if (v != p && sub[v] > sub[mc])
            mc = v;
    if (mc != 0)
        HLD(mc, u);
    for (int &v : adj[u])
        if (v != p && v != mc)
        {
            ++cur;
            HLD(v, u);
        }
}

void get_ans(const SQuery &a, int pr)
{
    int u = a.u, v = a.v, su = 0, ch = 0;
    while (col[u] != col[v])
    {
        if (h[rt[col[u]]] < h[rt[col[v]]])
            swap(u, v);
        su += sum.que(in[rt[col[u]]], in[u]);
        ch += chk.que(in[rt[col[u]]], in[u]);
        u = par[rt[col[u]]];
    }
    if (h[u] < h[v])
        swap(u, v);
    su += sum.que(in[v], in[u]);
    ch += chk.que(in[v], in[u]);
    (ans[a.ind] *= pw(pr, su + ch * a.x)) %= MOD;
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    for (int i = 1; i <= n; i++)
    {
        for (scanf("%d", &x); x != 1; x /= d[x])
            pro.push_back(d[x]);
        sort(pro.begin(), pro.end());
        pro.push_back(-1);
        int cnt = 1;
        for (unsigned int j = 1; j < pro.size(); j++)
        {
            if (pro[j] == pro[j - 1])
                cnt++;
            else
            {
                val[pos[pro[j - 1]]].push_back({cnt, i});
                cnt = 1;
            }
        }
        pro.clear();
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        ans[i] = 1;
        for (scanf("%d%d%d", &u, &v, &x); x != 1; x /= d[x])
            pro.push_back(d[x]);
        sort(pro.begin(), pro.end());
        pro.push_back(-1);
        int cnt = 1;
        for (unsigned int j = 1; j < pro.size(); j++)
        {
            if (pro[j] == pro[j - 1])
                cnt++;
            else
            {
                que[pos[pro[j - 1]]].push_back((SQuery){u, v, cnt, i});
                cnt = 1;
            }
        }
        pro.clear();
    }
    for (int i = 1; i <= pr; i++)
    {
        if (que[i].empty() || val[i].empty())
            continue;
        sort(que[i].begin(), que[i].end(), [](const SQuery &a, const SQuery &b) { return a.x > b.x; });
        sort(val[i].begin(), val[i].end(), greater<pair<int, int>>());
        for (pair<int, int> &u : val[i])
            sum.upd(in[u.se], u.fi);
        unsigned int pt = 0;
        for (SQuery &u : que[i])
        {
            for (; pt < val[i].size() && val[i][pt].fi >= u.x; pt++)
            {
                sum.upd(in[val[i][pt].se], -val[i][pt].fi);
                chk.upd(in[val[i][pt].se], 1);
            }
            get_ans(u, sav[i - 1]);
        }
        for (unsigned int j = 0; j < pt; j++)
            chk.upd(in[val[i][j].se], -1);
        for (unsigned int j = pt; j < val[i].size(); j++)
            sum.upd(in[val[i][j].se], -val[i][j].fi);
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
}
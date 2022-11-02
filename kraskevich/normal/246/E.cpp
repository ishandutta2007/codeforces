#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct node
{
    int l, r, sum;
    node * left, * right;
    node(int _l = 0, int _r = 0, int _sum = 0, node * _left = NULL, node * _right = NULL): l(_l), r(_r), sum(_sum), left(_left), right(_right) {}
};

node * build(int l, int r)
{
    int m = (l + r) / 2;
    node * t = new node(l, r, 0, l == r ? NULL : build(l, m), l == r ? NULL : build(m + 1, r));
    return t;
}

node * update(int pos, int newVal, node * prev)
{
    node * t = new node(prev->l, prev->r, newVal, NULL, NULL);
    if (prev->l != prev->r)
    {
        int m = (prev->l + prev->r) / 2;
        if (pos <= m)
            t->left = update(pos, newVal, prev->left), t->right = prev->right;
        else
            t->left = prev->left, t->right = update(pos, newVal, prev->right);
        t->sum = t->left->sum + t->right->sum;
    }
    return t;
}

int getSum(int l, int r, node * t)
{
    if (l == t->l && r == t->r)
        return t->sum;
    int m = (t->l + t->r) / 2, sl = 0, sr = 0;
    if (l <= m)
        sl = getSum(l, min(r, m), t->left);
    if (r > m)
        sr = getSum(max(m + 1, l), r, t->right);
    return sl + sr;
}

const int N = 111111;
vector<int> g[N];
vector<int> atH[N];
vector<string> nameH[N];
vector<bool> isRoot(N, true);
string name[N];
int tin[N], tout[N], h[N];
int timer = 0;

void dfs(int v, int curH)
{
    h[v] = curH;
    tin[v] = timer++;
    atH[curH].push_back(tin[v]);
    nameH[curH].push_back(name[v]);
    for (int i = 0; i < g[v].size(); ++i)
        dfs(g[v][i], curH + 1);
    tout[v] = timer++;
}

typedef node * pnode;
vector<pnode> root[N];

void calc(int curH)
{
    if (atH[curH].size() == 0)
        return;
    node * prev = build(0, atH[curH].size() - 1);
    map<string, int> pos;
    for (int i = atH[curH].size() - 1; i >= 0; --i)
    {
        string cur = nameH[curH][i];
        node * mid, * last;
        if (pos.count(cur))
            mid = update(pos[cur], 0, prev);
        else
            mid = prev;
        pos[cur] = i;
        last = update(pos[cur], 1, mid);
        prev = last;
        root[curH].push_back(last);
    }
    reverse(root[curH].begin(), root[curH].end());
}

int getAns(int v, int k)
{
    int curH = h[v] + k;
    int l = lower_bound(atH[curH].begin(), atH[curH].end(), tin[v]) - atH[curH].begin();
    int r = lower_bound(atH[curH].begin(), atH[curH].end(), tout[v]) - atH[curH].begin();
    --r;
    if (l == atH[curH].size() || l > r || (r >= 0 && r < atH[curH].size() && atH[curH][r] > tout[v]))
        return 0;
    else
        return getSum(l, r, root[curH][l]);
}
        
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> name[i];

        int v;
        cin >> v;
        
        if (v == 0)
            continue;
        --v;
        isRoot[i] = 0;
        g[v].push_back(i);
    }
    
    for (int i = 0; i < n; ++i)
        if (isRoot[i])
            dfs(i, 0);
    for (int i = 0; i < n; ++i)
        calc(i);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int v, k;
        cin >> v >> k;
        cout << getAns(v - 1, k) << "\n";
    }
    

    return 0;
}
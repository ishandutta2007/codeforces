#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;


struct Node
{
    Node *L, *R;
    int sum;

    Node() {}
    Node(Node *L, Node *R, int sum)
    {
        this->L = L;
        this->R = R;
        this->sum = sum;
    }
};


struct Tree
{
    const static int L = 1;
    const static int R = N;

    Node *root;

    Tree(): root(NULL) {}

    int getSum(Node *t, int l, int r, int tl, int tr)
    {
        if (!t)
            return 0;
        if (l == tl && r == tr)
            return t->sum;
        int m = (tl + tr) / 2;
        int sl = 0;
        int sr = 0;
        if (l <= m)
            sl = getSum(t->L, l, min(r, m), tl, m);
        if (r > m)
            sr = getSum(t->R, max(m + 1, l), r, m + 1, tr);
        return sl + sr;
    }

    int getSum(int l, int r)
    {
        return getSum(root, l, r, L, R);
    }

    void add(Node *&t, int pos, int tl, int tr, int by)
    {
        if (!t)
            t = new Node(NULL, NULL, 0);
        t->sum += by;
        if (tl == tr)
            return;
        int m = (tl + tr) / 2;
        if (pos <= m)
            add(t->L, pos, tl, m, by);
        else
            add(t->R, pos, m + 1, tr, by);
    }

    void add(int pos, int by)
    {
        add(root, pos, L, R, by);
    }

    void clear()
    {
        clear(root);
    }

    void clear(Node *t)
    {
        if (!t)
            return;
        clear(t->L);
        clear(t->R);
        delete t;
    }
};

Tree tree[N];
map<int, int> cnt[N];
vector<int> g[N];
vector<int> kk[N];
vector<int> id[N];
int ans[N];
bool u[N];
int c[N];

void merge(map<int, int> &a, map<int, int> &b, Tree &ta, Tree &tb)
{
    if (a.size() < b.size())
    {
        a.swap(b);
        swap(ta.root, tb.root);
    }
    for (auto it = b.begin(); it != b.end(); it++)
    {
        if (a.count(it->first))
            ta.add(a[it->first], -1);
        a[it->first] += it->second;
        ta.add(a[it->first], 1);
    }
    b.clear();
    tb.clear();
}

void dfs(int v)
{
    u[v] = true;
    cnt[v][c[v]] = 1;
    tree[v].add(1, 1);
    for (int to : g[v])
        if (!u[to])
        {
            dfs(to);
            merge(cnt[v], cnt[to], tree[v], tree[to]);
        }
    for (int i = 0; i < kk[v].size(); i++)
    {
        int k = kk[v][i];
        int d = id[v][i];
        ans[d] = tree[v].getSum(k, N);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int v, k;
        cin >> v >> k;
        --v;
        kk[v].push_back(k);
        id[v].push_back(i);
    }
    fill(u, u + n, 0);
    dfs(0);
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

long long val(long long n)
{
    return n * (n + 1) / 2;
}

struct Node
{
    long long inner;
    long long suf;
    long long pref;
    bool all;

    Node(long long in = 0, long long p = 0, long long s = 0, bool a = true)
    {
        inner = in;
        pref = p;
        suf = s;
        all = a;
    }

    void merge(Node a, Node b)
    {
        inner = a.inner + b.inner;
        all = (a.all && b.all);
        pref = a.pref;
        suf = b.suf;
        if (!a.all && !b.all)
            inner += val(a.suf + b.pref);
        if (b.all)
            suf = b.suf + a.suf;
        if (a.all)
            pref = a.pref + b.pref;
    }
};

struct SegmTree
{
    vector<Node> tree;
    int sz;

    SegmTree(int n = 0)
    {
        tree.assign(4 * n, Node());
        if (!n)
            return;
        sz = n;
        build(0, 0, sz - 1);
    }

    void build(int i, int l, int r)
    {
        tree[i] = Node(0, 0, 0, false);
        if (l == r)
            return;
        int m = (l + r) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m + 1, r);
    }

    long long getSum()
    {
        Node root = tree[0];
        if (root.all)
            return val(sz);
        else
            return root.inner + val(root.pref) + val(root.suf);
    }

    void put(int pos, int val)
    {
        put(0, pos, 0, sz - 1, val);
    }

    void put(int i, int pos, int tl, int tr, int val)
    {
        if (tl == pos && tr == pos) {
            tree[i].pref = tree[i].suf = tree[i].all = val;
            tree[i].inner = 0;
            return;
        }
        int m = (tl + tr) / 2;
        if (pos <= m)
            put(2 * i + 1, pos,tl, m, val);
        else
            put(2 * i + 2, pos, m + 1, tr, val);
        tree[i].merge(tree[2 * i + 1], tree[2 * i + 2]);
    }
};

SegmTree st[20];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 20; i++)
        st[i] = SegmTree(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < 20; j++)
            if (a & (1 << j))
                st[j].put(i, 1);
            else
                st[j].put(i, 0);
    }
    for (int i = 0; i < m; i++)
    {
        int p;
        int v;
        cin >> p >> v;
        --p;
        for (int j = 0; j < 20; j++)
            if (v & (1 << j))
                st[j].put(p, 1);
            else
                st[j].put(p, 0);
        long long res = 0;
        /*for (int j = 0; j < 4; j++)
            cerr << st[j].getSum() << " ";
        cerr << endl;*/
        for (int j = 0; j < 20; j++)
            res += (1 << j) * st[j].getSum();
        cout << res << "\n";
    }

    return 0;
}
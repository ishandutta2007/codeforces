#include <bits/stdc++.h>

#define prev lol
#define F first
#define S second

using namespace std;
typedef long long ll;
const int max_n = 300111, inf = 2e9 + 2, mod = 1e9 + 7;

vector<int> v[max_n];
vector<int> order;
int depth[max_n];
int num[max_n];
int subtree_sz[max_n];
pair<ll, ll> tree[max_n * 4]; //x, k (  x    k * depth)
pair<int, int> zp = make_pair(0, 0);

void DFS(int cur, int d)
{
    order.push_back(cur);
    depth[cur] = d;
    num[cur] = order.size() - 1;
    int sz = 1;
    for (int i = 0; i < v[cur].size(); ++i)
    {
        DFS(v[cur][i], d + 1);
        sz += subtree_sz[v[cur][i]];
    }
    subtree_sz[cur] = sz;
}

void add_value(int cur, int l, int r, int al, int ar, int x, int k)
{
    if (l == al && r == ar)
    {
        tree[cur].F += x;
        tree[cur].F %= mod;
        tree[cur].S += k;
        tree[cur].S %= mod;
        return;
    }

    if (al > r || ar < l)
    {
        return;
    }

    int mid = (l + r) / 2;

    add_value(cur * 2, l, mid, al, min(mid, ar), x, k);
    add_value(cur * 2 + 1, mid + 1, r, max(mid + 1, al), ar, x, k);
}

int get_value(int cur, int l, int r, int pos, ll x, ll k)
{
    if (l == r)
    {
        x = (x + tree[cur].F) % mod;
        k = (k + tree[cur].S) % mod;
        ll d = depth[order[l]];
        ll ans = x - (k * d) % mod;
        ans %= mod;
        if (ans < 0)
        {
            ans += mod;
        }
        return ans;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        return get_value(cur * 2, l, mid, pos, (x + tree[cur].F) % mod, (k + tree[cur].S) % mod);
    }
    else
    {
        return get_value(cur * 2 + 1, mid + 1, r, pos, (x + tree[cur].F) % mod, (k + tree[cur].S) % mod);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &a);
        a--;
        v[a].push_back(i);
    }

    DFS(0, 0);

/*
    for (int i = 0; i < n; ++i) cout << order[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i) cout << num[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i) cout << depth[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i) cout << subtree_sz[i] << ' ';
    cout << endl;*/

    int qNumber, type, ver, x, k;
    scanf("%d", &qNumber);
    for (int i = 0; i < qNumber; ++i)
    {
        scanf("%d%d", &type, &ver);
        ver--;
        if (type == 1)
        {
            scanf("%d%d", &x, &k);
            int l = num[ver];
            int r = l + subtree_sz[ver] - 1;
            ll lx = x + ((ll)k * (ll) depth[ver]) % mod;
            add_value(1, 0, n - 1, l, r, lx % mod, k);
        }
        else
        {
            printf("%d\n", get_value(1, 0, n - 1, num[ver], 0, 0));
        }
    }
    return 0;
}
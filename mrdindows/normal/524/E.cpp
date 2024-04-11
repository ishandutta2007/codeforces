#include <bits/stdc++.h>

using namespace std;

#define left askl
#define right askk
const int maxn = 300007, logn = 23;
const int maxm = maxn * logn;
int inf;
int root[maxn], left[maxm], right[maxm];
int num[maxm];
int sz;
int rt;

void init()
{
    sz = 1;
    rt = 1;
    memset(num, 63, sizeof(num));
    memset(root, 0, sizeof(root));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    inf = num[0];
    memset(num, -1, sizeof(num));
}

int copy(int v)
{
    left[sz] = left[v];
    right[sz] = right[v];
    num[sz] = num[v];
    return sz++;
}

void make_root()
{
    root[rt] = copy(root[rt - 1]);
    rt++;
}

void change(int pos, int c, int v = root[rt - 1], int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        num[v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(pos < m)
        change(pos, c, left[v] = copy(left[v]), l, m);
    else
        change(pos, c, right[v] = copy(right[v]), m, r);
    num[v] = min(num[left[v]], num[right[v]]);
}

int get(int L, int R, int v, int l = 0, int r = maxn)
{
    if(L <= l && r <= R)
        return num[v];
    if(r <= L || R <= l)
        return inf;
    int m = (l + r) / 2;
    return min(get(L, R, left[v], l, m), get(L, R, right[v], m, r));
}

bool gt(int l, int r, int a, int b)
{
    int t = get(a, b + 1, root[r]);
    return get(a, b + 1, root[r]) >= l;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> lad(k);
    for(int i = 0; i < k; i++)
        cin >> lad[i].first >> lad[i].second;
    tuple<int, int, int, int> Q[q];
    for(int i = 0; i < q; i++)
        cin >> get<0>(Q[i]) >> get<1>(Q[i]) >> get<2>(Q[i]) >> get<3>(Q[i]);
    int ans[q];
    memset(ans, 0, sizeof(ans));
    for(int z = 0; z < 2; z++)
    {
        init();
        vector<int> LAD[n + 1];
        int pos[m + 1];
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < k; i++)
            LAD[lad[i].first].push_back(lad[i].second);

        for(int i = 1; i <= n; i++)
        {
            make_root();
            for(auto it: LAD[i])
            {
                change(it, i);
            }
        }
        for(int i = 0; i < q; i++)
        {
            ans[i] |= gt(get<0>(Q[i]), get<2>(Q[i]), get<1>(Q[i]), get<3>(Q[i]));
        }

        swap(n, m);
        for(int i = 0; i < k; i++)
            swap(lad[i].first, lad[i].second);
        for(int i = 0; i < q; i++)
            swap(get<0>(Q[i]), get<1>(Q[i])),
            swap(get<2>(Q[i]), get<3>(Q[i]));
    }
    for(int i = 0; i < q; i++)
        if(ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    return 0;
}
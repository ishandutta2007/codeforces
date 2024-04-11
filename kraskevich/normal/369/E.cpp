#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 10;

vector<int> R[4 * N + 10];
vector<int> at[N + 10];

void build(int i, int l, int r)
{
    if (l == r)
    {
        R[i] = at[l];
        sort(R[i].begin(), R[i].end());
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    R[i].resize(R[2 * i + 1].size() + R[2 * i + 2].size());
    merge(R[2 * i + 1].begin(), R[2 * i + 1].end(), R[2 * i + 2].begin(), R[2 * i + 2].end(), R[i].begin());
}

int sum(int i, int l, int r, int tl, int tr, int y)
{
    if (l == tl && r == tr)
    {
        int pos = lower_bound(R[i].begin(), R[i].end(), y) - R[i].begin();
        return R[i].size() - pos;
    }
    int m = (tl + tr) / 2;
    int sl = 0;
    int sr = 0;
    if (l <= m)
        sl = sum(2 * i + 1, l, min(r, m), tl, m, y);
    if (r > m)
        sr = sum(2 * i + 2, max(m + 1, l), r, m + 1, tr, y);
    return sl + sr;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        at[l].push_back(r);
    }
    build(0, 0, N);
    for (int i = 0; i < m; i++)
    {
        int cnt;
        cin >> cnt;
        vector<int> a(cnt);
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        int old = 0;
        int tot = 0;
        for (int j = 0; j < a.size(); j++)
        {
            tot += sum(0, old, a[j], 0, N, a[j]);
            old = a[j] + 1;
        }
        cout << tot << "\n";
    }

    return 0;
}
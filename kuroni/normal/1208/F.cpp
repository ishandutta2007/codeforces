#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E6 + 5, MX = 1 << 21;

int n, ans = 0, a[N], fi[MX];
pair<int, int> lst[MX];

void add(int pos, int u)
{
    if (u > lst[pos].fi)
        swap(u, lst[pos].fi);
    if (u > lst[pos].se && u != lst[pos].fi)
        swap(u, lst[pos].se);
}

void DFS(int bi, int m1, int m2)
{
    if (bi == -1)
    {
        ans = max(ans, m1 | m2);
        return;
    }
    bool chk = false;
    if (fi[m1 ^ (1 << bi)] < lst[m2].se)
    {
        DFS(bi - 1, m1 ^ (1 << bi), m2);
        chk = true;
    }
    if (fi[m1] < lst[m2 ^ (1 << bi)].se)
    {
        DFS(bi - 1, m1, m2 ^ (1 << bi));
        chk = true;
    }
    if (!chk)
        DFS(bi - 1, m1, m2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fill(fi, fi + MX, n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fi[a[i]] = min(fi[a[i]], i);
        add(a[i], i);
    }
    for (int msk = MX - 1; msk >= 0; msk--)
        for (int i = 0; i < 21; i++)
            if (msk >> i & 1)
            {
                int oth = msk ^ (1 << i);
                fi[oth] = min(fi[oth], fi[msk]);
                add(oth, lst[msk].fi);
                add(oth, lst[msk].se);
            }
    DFS(20, 0, 0);
    cout << ans;
}
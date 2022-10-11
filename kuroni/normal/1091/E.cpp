#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, u, a[N], ind[N], cnt[N];
long long s[N], f[N];
vector<int> ve;

class CTree
{
#define m (l + r) / 2
#define lc (i * 2)
#define rc (i * 2) + 1

  private:
    struct SNode
    {
        long long mi, lz;

        SNode(long long _mi = 0, long long _lz = 0) : mi(_mi), lz(_lz) {};
    } tr[4 * N];

    void down(int i)
    {
        tr[lc].lz += tr[i].lz; tr[lc].mi += tr[i].lz;
        tr[rc].lz += tr[i].lz; tr[rc].mi += tr[i].lz;
        tr[i].lz = 0;
    }

  public:
    void build(int l, int r, int i)
    {
        if (l == r)
        {
            tr[i] = SNode(f[l], 0);
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        tr[i] = SNode(min(tr[lc].mi, tr[rc].mi), 0);
    }

    void upd(int l, int r, int i, int L, int R, long long v)
    {
        if (L > R)
            return;
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            tr[i].mi += v;
            tr[i].lz += v;
            return;
        }
        down(i);
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
        tr[i] = SNode(min(tr[lc].mi, tr[rc].mi), 0);
    }

    long long que() { return tr[1].mi; };

#undef m
#undef lc
#undef rc
} seg;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        ind[i] = i;
    }
    sort(a + 1, a + n + 1, greater<int>());
    sort(ind + 1, ind + n + 1, [](const int &x, const int &y) { return a[x] > a[y] || (a[x] == a[y] && x > y); });
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int cur = 0;
    long long sum = 0;
    for (int i = n; i >= 1; i--)
    {
        f[i] = 1LL * i * (i - 1) + sum + 1LL * cur * i - s[i];
        sum += min(i, a[i]);
        cnt[min(i, a[i])]++;
        cur += cnt[i];
        sum -= 1LL * i * cnt[i];
    }
    seg.build(1, n, 1);
    if (seg.que() >= 0 && s[n] % 2 == 0)
        ve.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int u = ind[i];
        // update minus side
        seg.upd(1, n, 1, u, n, 1);

        // update plus side
        seg.upd(1, n, 1, a[u], u - 1, -1);
    
        if (seg.que() >= 0 && s[n] % 2 == i % 2)
            ve.push_back(i);
    }
    if (ve.empty())
        printf("-1");
    else
        for (int &v : ve)
            printf("%d ", v);
}
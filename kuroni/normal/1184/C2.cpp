#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MX = 2E6 + 5;

int n, r, x, y, ans = 0;

struct SEvent
{
    int x, y, typ;
};
vector<SEvent> ve;

class CTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

  private:
    int tr[12 * MX], lz[12 * MX];

    void down(int i)
    {
        tr[lc] += lz[i]; lz[lc] += lz[i];
        tr[rc] += lz[i]; lz[rc] += lz[i];
        lz[i] = 0;
    }

  public:
    void upd(int l, int r, int i, int L, int R, int v)
    {
        if (l > R || r < L || L > R)
            return;
        if (L <= l && r <= R)
        {
            tr[i] += v;
            lz[i] += v;
            return;
        }
        down(i);
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
        tr[i] = max(tr[lc], tr[rc]);
    }

    int que()
    {
        return tr[1];
    }

#undef m
#undef lc
#undef rc
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r; r *= 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        x -= y; y = x + 2 * y;
        x += MX; y += MX;
        ve.push_back((SEvent){x, y, 0});
        ve.push_back((SEvent){x + r, y, 1});
    }
    sort(ve.begin(), ve.end(), [](const SEvent &a, const SEvent &b) {
        return a.x < b.x || (a.x == b.x && a.typ < b.typ);
    });
    for (SEvent &cur : ve)
    {
        seg.upd(1, 3 * MX, 1, cur.y, cur.y + r, cur.typ == 0 ? 1 : -1);
        ans = max(ans, seg.que());
    }
    cout << ans;
}
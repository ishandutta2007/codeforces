#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, LOG = 19;

vector<int> cur, ve[N];
string s;
int n, q, mx, x, y, a, val[N][LOG];
long long ans;

struct SNode
{
    long long val;
    int cnt;
    bool lz;

    inline SNode operator+(const SNode &b)
    {
        return (SNode){val + b.val, cnt + b.cnt, false};
    }
};

struct SQuery
{
    int pos;
    bool get;
};
vector<SQuery> que;

class CTree
{
#define lc i * 2
#define rc i * 2 + 1
#define m (l + r) / 2
  private:
    SNode tr[4 * N];

    void down(int i)
    {
        if (tr[i].lz)
            tr[lc] = tr[rc] = (SNode){0, 0, true};
        tr[i].lz = false;
    }

  public:
    void upd(int l, int r, int i, int u, int cnt, long long val)
    {
        if (l == r)
        {
            tr[i].cnt += cnt;
            tr[i].val += val;
            return;
        }
        down(i);
        if (u <= m)
            upd(l, m, lc, u, cnt, val);
        else
            upd(m + 1, r, rc, u, cnt, val);
        tr[i] = tr[lc] + tr[rc];
    }

    void clear(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            tr[i] = (SNode){0, 0, true};
            return;
        }
        down(i);
        clear(l, m, lc, L, R);
        clear(m + 1, r, rc, L, R);
        tr[i] = tr[lc] + tr[rc];
    }

    SNode que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return (SNode){0, 0, false};
        if (L <= l && r <= R)
            return tr[i];
        down(i);
        return que(l, m, lc, L, R) + que(m + 1, r, rc, L, R);
    }
#undef lc
#undef rc
#undef m
} seg;

int get(int u, int v)
{
    return u > n ? 0 : val[u][v];
}

void init()
{
    mx = 32 - __builtin_clz(n - 1);
    for (int i = 1; i <= n; i++)
        ve[s[i - 1] - 'a' + 1].push_back(i);
    int cnt = 0;
    for (int i = 1; i <= 26; i++)
        if (!ve[i].empty())
        {
            cnt++;
            for (int &v : ve[i])
            {
                cur.push_back(v);
                val[v][0] = cnt;
            }
            ve[i].clear();
        }
    for (int j = 1; j <= mx; j++)
    {
        int add = 1 << (j - 1);
        for (int i = n + 1; i <= n + add; i++)
            ve[get(i - add, j - 1)].push_back(i - add);
        for (int &v : cur)
            if (v > add)
                ve[get(v - add, j - 1)].push_back(v - add);
        int cnt = 0;
        cur.clear();
        for (int i = 1; i <= n; i++)
        {
            int pre = -1;
            for (int &v : ve[i])
            {
                if (get(v + add, j - 1) != pre)
                {
                    cnt++;
                    pre = get(v + add, j - 1);
                }
                cur.push_back(v);
                val[v][j] = cnt;
            }
            ve[i].clear();
        }
    }
}

int find(int u, int v)
{
    int ans = 0;
    for (int i = mx; i >= 0; i--)
        if (get(u, i) == get(v, i))
        {
            ans += (1 << i);
            u += (1 << i);
            v += (1 << i);
        }
    return ans;
}

void find_ans()
{
    seg.clear(1, n, 1, 1, n);
    int pre = -1;
    for (SQuery &v : que)
        if (!v.get)
        {
            if (pre != -1)
            {
                int val = find(pre, v.pos), cnt = seg.que(1, n, 1, val + 1, n).cnt;
                seg.clear(1, n, 1, val + 1, n);
                seg.upd(1, n, 1, val, cnt, 1LL * val * cnt);
            }
            pre = v.pos;
            seg.upd(1, n, 1, n - pre + 1, 1, n - pre + 1);
        }
        else if (pre != -1)
        {
            int val = find(pre, v.pos);
            ans += seg.que(1, n, 1, 1, val).val + 1LL * seg.que(1, n, 1, val + 1, n).cnt * val;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> s;
    init();
    while (q--)
    {
        ans = 0;
        que.clear();
        cin >> x >> y;
        while (x--)
        {
            cin >> a;
            que.push_back((SQuery){a, false});
        }
        while (y--)
        {
            cin >> a;
            que.push_back((SQuery){a, true});
        }
        sort(que.begin(), que.end(), [](const SQuery &a, const SQuery &b) { return val[a.pos][mx] < val[b.pos][mx]; });
        find_ans();
        reverse(que.begin(), que.end());
        find_ans();
        cout << ans << '\n';
    }
}
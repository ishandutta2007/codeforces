#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 400005, MOD = 1E9 + 7, MX = 305;

int n, q, l, r, v, a[N];
long long inv[MX], msk[MX];
string ty;
vector<int> pr;

inline pair<long long, long long> operator+(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    return mp(a.fi * b.fi % MOD, a.se | b.se);
}

long long pw(long long u, int p)
{
    long long ret = 1;
    for (int i = 31 - __builtin_clz(p); i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

class CTree
{
#define m (l + r) / 2
#define lc i * 2
#define rc i * 2 + 1

  private:
    pair<long long, long long> val[4 * N], lz[4 * N];

    void down(int l, int r, int i)
    {
        val[lc] = val[lc] + mp(pw(lz[i].fi, m - l + 1), lz[i].se);
        lz[lc] = lz[lc] + lz[i];
        val[rc] = val[rc] + mp(pw(lz[i].fi, r - m), lz[i].se);
        lz[rc] = lz[rc] + lz[i];
        lz[i] = mp(1, 0);
    }

  public:
    void build(int l, int r, int i)
    {
        lz[i] = mp(1, 0);
        if (l == r)
        {
            val[i] = mp(a[l], msk[a[l]]);
            return;
        }
        build(l, m, lc);
        build(m + 1, r, rc);
        val[i] = val[lc] + val[rc];
    }

    void upd(int l, int r, int i, int L, int R, int v)
    {
        if (l > R || r < L)
            return;
        if (L <= l && r <= R)
        {
            val[i] = val[i] + mp(pw(v, r - l + 1), msk[v]);
            lz[i] = lz[i] + mp(v, msk[v]);
            return;
        }
        down(l, r, i);
        upd(l, m, lc, L, R, v);
        upd(m + 1, r, rc, L, R, v);
        val[i] = val[lc] + val[rc];
    }

    pair<long long, long long> que(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L)
            return mp(1, 0);
        if (L <= l && r <= R)
            return val[i];
        down(l, r, i);
        return que(l, m, lc, L, R) + que(m + 1, r, rc, L, R);
    }

#undef m
#undef lc
#undef rc
} seg;

void init()
{
    for (int i = 2; i < MX; i++)
        if (msk[i] == 0)
        {
            for (int j = i; j < MX; j += i)
                msk[j] |= (1LL << pr.size());
            pr.push_back(i);
        }
    inv[1] = 1;
    for (int i = 2; i < MX; i++)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    seg.build(1, n, 1);
    while (q--)
    {
        cin >> ty >> l >> r;
        if (ty == "MULTIPLY")
        {
            cin >> v;
            seg.upd(1, n, 1, l, r, v);
        }
        else
        {
            pair<long long, long long> ans = seg.que(1, n, 1, l, r);
            for (int i = 0; i < pr.size(); i++)
                if (ans.se >> i & 1)
                    (ans.fi *= (pr[i] - 1) * inv[pr[i]] % MOD) %= MOD;
            cout << ans.fi << '\n';
        }
    }
}
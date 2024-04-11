#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
int n;
int p[N], a[N];
ll ans[N];
ll bit1[N], bit2[N];
set <int> s, t;
ll se[N * 4], mx[N * 4], mxc[N * 4];
ll ch[N];
ll df[N];
void pass(int id, int c)
{
    if(mx[c] > mx[id])
    {
        mx[c] = mx[id];
    }
}
void push(int id)
{
    pass(id, id * 2);
    pass(id, id * 2 + 1);
}
void pull(int id){
    mx[id] = max(mx[id * 2], mx[id * 2 + 1]);
    mxc[id] = 0;
    if(mx[id] == mx[id * 2])
    {
        mxc[id] += mxc[id * 2];
    }
    if(mx[id] == mx[id * 2 + 1])
    {
        mxc[id] += mxc[id * 2 + 1];
    }
    se[id] = max(se[id * 2], se[id * 2 + 1]);
    if(mx[id * 2] != mx[id])
    {
        se[id] = max(se[id], mx[id * 2]);
    }
    if(mx[id * 2 + 1] != mx[id])
    {
        se[id] = max(se[id], mx[id * 2 + 1]);
    }
}
int sz = 0;
void upd(int id, int l, int r, int al, int ar, int v)
{
    if(l > ar || r < al || mx[id] <= v)
    {
        return;
    }
    if(al <= l && r <= ar && se[id] < v)
    {
        ch[++sz] = mx[id];
        df[mx[id]] -= mxc[id];
        mx[id] = v;
        ch[++sz] = mx[id];
        df[mx[id]] += mxc[id];
        return;
    }
    push(id);
    int m = (r + l) / 2;
    upd(id * 2, l, m, al, ar, v);
    upd(id * 2 + 1, m + 1, r, al, ar, v);
    pull(id);
}
void upd2(int id, int l, int r, int p, int v)
{
    if(l == r)
    {
        ch[++sz] = mx[id];
        df[mx[id]] -= mxc[id];
        mx[id] = v;
        ch[++sz] = mx[id];
        df[mx[id]] += mxc[id];
        return;
    }
    push(id);
    int midd = (r + l) / 2;
    if(p <= midd)
    {
        upd2(id * 2, l, midd, p, v);
    }
    else
    {
        upd2(id * 2 + 1, midd + 1, r, p, v);
    }
    pull(id);
}
void build(int id, int l, int r)
{
    mx[id] = 0;
    mxc[id] = r - l + 1;
    se[id] = -1e9;
    if(l == r)
    {
        return ;
    }
    build(id * 2, l, (r + l) / 2);
    build(id * 2 + 1, (r + l) / 2 + 1, r);
}
void bupd1(int id, ll v)
{
    for(int i = id; i <= n; i += i & -i)
    {
        bit1[i] += v;
    }
}
void bupd2(int id, ll v)
{
    for(int i = id; i <= n; i += i & -i)
    {
        bit2[i] += v;
    }
}
ll bqry1(int id)
{
    ll res = 0;
    for(int i = id; i >= 1; i -= i & -i)
    {
        res += bit1[i];
    }
    return res;
}
ll bqry2(int id)
{
    ll res = 0;
    for(int i = id; i >= 1; i -= i &-i)
    {
        res += bit2[i];
    }
    return res;
}
void funct(int mg)
{
    s.clear();
    t.clear();
    build(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        bit1[i] = bit2[i] = 0;
    }
    s.insert(p[1]);
    t.insert(p[1]);
    bupd1(p[1], 1);
    int mx1 = p[1];
    upd2(1, 1, n, p[1], p[1]);
    bupd2(p[1], -1);
    ll tot = -1;
    for(int i = 2; i <= n; i++)
    {
        int cur = p[i];
        auto it = s.lower_bound(cur);
        bool rm = (it == s.end());
        int nxt = 0;
        if(!rm)
        {
            nxt = *it;
        }
        if(it == s.begin())
        {
            tot -= bqry1(cur);
            bupd2(cur, -1);
            t.insert(cur);
            upd2(1, 1, n, cur, mx1);
        }
        else
        {
            int prv = *(--it);
            upd(1, 1, n, 1, prv, prv);
            if(rm)
            {
                mx1 = cur;
            }
            else
            {
                upd2(1, 1, n, nxt, mx1);
                if(t.find(nxt) == t.end())
                {
                    tot -= bqry1(nxt);
                    bupd2(nxt, -1);
                    t.insert(nxt);
                }
            }
            upd2(1, 1, n, *s.begin(), mx1);
        }
        s.insert(cur);
        tot += bqry2(n) - bqry2(cur - 1);
        bupd1(cur, 1);
        for(int j = 1; j <= sz; j++)
        {
            if(ch[j] != 0 && df[ch[j]] != 0)
            {
                tot += df[ch[j]] * bqry1(ch[j]);
                bupd2(ch[j], df[ch[j]]);
                df[ch[j]] = 0;
            }
        }
        sz = 0;
        ans[i] += tot;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        p[a[i]] = i;
        ans[i] = 0;
    }
    funct(1);
    for(int i = 1; i <= n; i++)
    {
        p[i] = n - p[i] + 1;
    }
    funct(0);
    for(int i = 1; i <= n; i++)
    {
        ans[i]++;
        cout << ans[i] << "\n";
    }
    return 0;
}
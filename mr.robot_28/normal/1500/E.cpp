#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 4e5;
ll tree_cnt[4 * N], tree_sum[N * 4], tree_sum1[4 * N];
void upd(int v)
{
        tree_sum[v] = tree_sum[v * 2] + tree_sum[v * 2 + 1];
    tree_cnt[v] =tree_cnt[v * 2] + tree_cnt[v * 2 + 1];
    tree_sum1[v] = tree_sum1[v * 2] + tree_sum1[v * 2 + 1] + tree_cnt[v * 2] * tree_sum[v * 2 + 1];
}
void update(int v, int l, int r, int ind, int c, ll val)
{
    if(l == r)
    {
        tree_cnt[v] += c;
        tree_sum[v] += val;
        return;
    }
    if(ind <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, ind, c, val);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, ind, c, val);
    }
    upd(v);
}
void presum(int v, int l, int r, int x, ll & Sum, ll& Cnt, ll& Sum1)
{
    if(x == 0)
    {
        Sum = Cnt = Sum1 = 0;
        return;
    }
    if(l == r)
    {
        Sum = tree_sum[v];
        Cnt = tree_cnt[v];
        Sum1 = tree_sum1[v];
        return;
    }
    if(tree_cnt[v * 2] >= x)
    {
        presum(v * 2, l, (r + l) / 2, x, Sum, Cnt, Sum1);
    }
    else
    {
        ll Sum2, Cnt2, Sum2_1;
        presum(v * 2 + 1, (r + l)/ 2 + 1, r, x - tree_cnt[v * 2], Sum2, Cnt2, Sum2_1);
        Sum1 = Sum2_1 + tree_sum1[v * 2] + tree_cnt[v * 2] * Sum2;
        Sum = Sum2 + tree_sum[v * 2];
        Cnt = Cnt2 + tree_cnt[v * 2];
    }
}
void sufsum(int v, int l, int r, int x, ll & Sum, ll& Cnt, ll& Sum1)
{
    if(x == 0)
    {
        Sum = Cnt = Sum1 = 0;
        return;
    }
    if(l == r)
    {
        Sum = tree_sum[v];
        Cnt = tree_cnt[v];
        Sum1 = tree_sum1[v];
        return;
    }
    if(tree_cnt[v * 2 + 1] >= x)
    {
        sufsum(v * 2 + 1, (r + l) / 2 + 1, r, x, Sum, Cnt, Sum1);
    }
    else
    {
        ll Sum2, Cnt2, Sum2_1;
        sufsum(v * 2, l, (r + l) / 2, x - tree_cnt[v * 2 + 1], Sum2, Cnt2, Sum2_1);
        Sum1 =Sum2_1 + tree_sum1[v * 2 + 1] + Cnt2 * tree_sum[v * 2 + 1];
        Sum =Sum2+ tree_sum[v * 2 + 1];
        Cnt =Cnt2 + tree_cnt[v * 2 + 1];
    }
}
int _sz;
int m;
ll f(int x)
{
    ll Sum1, Cnt1, Sum1_1;
    ll Sum2, Cnt2, Sum2_1;
    presum(1, 0, m - 1, x + 1, Sum1, Cnt1, Sum1_1);
    sufsum(1, 0, m - 1, x, Sum2, Cnt2, Sum2_1);
    return Sum1 - Sum2;
}
ll prefsum(int x)
{
    ll Sum1, Cnt1, Sum1_1;
    ll Sum2, Cnt2, Sum2_1;
    presum(1, 0, m - 1, x, Sum1, Cnt1, Sum1_1);
    sufsum(1, 0, m - 1, x, Sum2, Cnt2, Sum2_1);
   // cout << "G " << Sum1 << " "<< Sum1_1 << " " << Sum2_1 << "\n";
    return Sum1 * x - Sum1_1 - Sum2_1;
}
ll suffsum(int x)
{
    return tree_sum[1] * _sz - tree_sum1[1] * 2 - prefsum(x);
}
void query()
{
    if(_sz == 0)
    {
        cout << 0 << "\n";
        return;
    }
    int p_sz = (_sz - 1) / 2;
    ll ans = 0;
    if(f(p_sz) >= 0)
    {
        ans += tree_sum[1] * _sz - tree_sum1[1] * 2;
    }
    else
    {
        int l = 0, r = p_sz;
        while(r > l)
        {
            int midd = (r + l) / 2;
            if(f(midd) < 0)
            {
                r = midd;
            }
            else
            {
                l = midd + 1;
            }
        }
    //    cout << l << " ";
        ans += prefsum(l);
      //  cout << ans << " ";
        l = p_sz;
        r = _sz - 1;
        while(r > l)
        {
            int midd = (l + r) / 2;
            if(f(midd) >= 0)
            {
                r = midd;
            }
            else
            {
                l = midd + 1;
            }
        }
      //  cout << l << "\n";
        ans += suffsum(l);
    }
    cout << tree_sum[1] - ans << "\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector <ll> s(n);
    ll sum = 0;
    fill(tree_sum, tree_sum + 4 *N, 0);
    fill(tree_cnt, tree_cnt + 4 * N, 0);
    fill(tree_sum1, tree_sum1 + 4 * N, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        sum += s[i];
    }
    vector <ll> val = s;
    vector <int> t(q);
    vector <ll> a(q);
    for(int i = 0; i < q; i++)
    {
        cin >> t[i] >> a[i];
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for(int i = 0; i < n; i++)
    {
        s[i] = lower_bound(val.begin(), val.end(), s[i]) - val.begin();
    }
    for(int i = 0; i < q; i++)
    {
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    }
    _sz = n;
    m = val.size();
    for(int i = 0; i< n; i++)
    {
        update(1, 0, m - 1, s[i], 1, val[s[i]]);
    }
    query();
    for(int i = 0; i < q; i++)
    {
        if(t[i] == 1)
        {
            _sz++;
            sum += val[a[i]];
            update(1, 0, m - 1, a[i], 1, val[a[i]]);
        }
        else
        {
            _sz--;
            sum -= val[a[i]];
            update(1, 0, m - 1, a[i], -1, -val[a[i]]);
        }
        query();
    }

    return 0;
}
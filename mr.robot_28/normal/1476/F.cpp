#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int N = 3e5 + 1000;
struct segTree{
    int n;
    bool mx;
    vector <int> t;
    void fix(int v)
    {
        t[v] = (mx ? max(t[v * 2 + 1], t[v * 2]) : min(t[v * 2], t[v * 2 + 1]));
    }
    void build(int v, int l, int r)
    {
        if(l == r)
        {
            t[v] = (mx ? -1e9 : 1e9);
        }
        else
        {
            int m = (r + l) / 2;
            build(v * 2,l, m);
            build(v * 2 + 1, m + 1, r);
            fix(v);
        }
    }
    void upd(int v, int l, int r, int pos, int val)
    {
        if(l == r)
        {
            t[v] = (mx ? max(t[v], val) : min(t[v], val));
        }
        else
        {
            int m = (r + l) / 2;
            if(pos <= m)
            {
                upd(v * 2,l, (r + l) / 2, pos, val);
            }
            else
            {
                upd(v * 2 + 1, m + 1, r, pos, val);
            }
            fix(v);
        }
    }
    int get(int v, int l, int r, int L, int R)
    {
        if(L > R)
        {
            return (mx ? -1e9 : 1e9);
        }
        if(R < l || L > r)
        {
            return (mx ? -1e9 : 1e9);
        }
        if(l >= L && r <= R)
        {
            return t[v];
        }
        int m = (r + l) / 2;
        int lf = get(v * 2, l, m, L, R);
        int rg = get(v * 2 + 1, m + 1, r, L, R);
        return (mx ? max(lf, rg) : min(lf, rg));
    }
    void upd(int pos, int val)
    {
        upd(1, 0, n - 1, pos, val);
    }
    int get(int L, int R)
    {
        return get(1, 0, n - 1, L, R);
    }
    void build()
    {
        build(1, 0, n - 1);
    }
    segTree(){};
    segTree(int n, bool mx):
        n(n),
        mx(mx)
    {
        t.resize(4 * n);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> p(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        vector <int> dp(n + 1, -1e9);
        vector<int> par(n + 1, -2);
        dp[0] = 0;
        par[0] = -1;
        vector <int> lf(n), rg(n);
        for(int i = 0; i < n; i++)
        {
            lf[i] = max(1, i - p[i] + 1);
            rg[i] = min(n, i + p[i] + 1);
        }
        segTree sn(n + 1, 0);
        segTree sx(n, 1);
        sn.build();
        sx.build();
        for(int i = 0; i < n; i++)
        {
            sx.upd(i, rg[i]);
        }
        sn.upd(0, 0);
        for(int i = 1; i <= n; i++)
        {
        //    cout << i << "\n";
            int j = i - 1;
            int k = lf[j] - 1;
            int m = sn.get(k, n);
          //  cout << "A " << m << "\n";
            if(m != 1e9)
            {
                int nval = max(sx.get(m, i - 2), i - 1);
                if(nval > dp[i])
                {
                    dp[i] = nval;
                    par[i] = m;
                }
            }
        //    cout << i << "\n";
            if(dp[j] >= i && max(dp[j], rg[j]) > dp[i])
            {
                dp[i] = max(dp[j], rg[j]);
                par[i] = -1;
            }
            if(dp[j] > dp[i])
            {
                dp[i] = dp[j];
                par[i] = -1;
            }
            sn.upd(dp[i], i);
        }
        if(dp[n] != n)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            string ans = "";
            int cur = n;
            while(cur != 0)
            {
                if(par[cur] == -1)
                {
                    cur--;
                    ans += "R";
                }
                else
                {
                    int pcur = par[cur];
                    ans += "L";
                    for(int j = 0; j < cur - pcur - 1; j++)
                    {
                        ans += "R";
                    }
                    cur = pcur;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
    return 0;
}
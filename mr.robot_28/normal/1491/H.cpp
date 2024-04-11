#include<bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int n, q;
vector <int> a, upd, nxt;
int T;
void re_calc(int l, int r)
{
    for(int j = l; j <= r; j++)
    {
        int u = max(0, a[j] - upd[l / T]);
        if(u < l)
        {
            nxt[j] = j;
        }
        else
        {
            nxt[j] = nxt[u];
        }
    }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    cin >> n >> q;
    a.resize(n);
    a[0] = -1;
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    T = 600;
    upd.resize(T);
    nxt.resize(n);
    for(int i = 0; i < n; i += T)
    {
        re_calc(i, min(n - 1, i + T - 1));
    }
    vector <int> vec1(3000), vec2(3000);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            int t1 = l / T;
            int t2 = r / T;
            int l1 = (t1 + 1) * T;
            int r1 = (t2) * T - 1;
            for(int j = l; j < min(l1, r + 1); j++)
            {
                a[j] = max(0, a[j] - x);
            }
            int l_0 = t1 * T;
            int r_0 = min(n - 1, (t1 + 1) * T - 1);
            re_calc(l_0, r_0);
            for(int j = r; j > max(r1, l1 - 1); j--)
            {
                a[j] = max(0, a[j] - x);
            }
            l_0 = t2 * T;
            r_0 = min(n - 1, (t2 + 1) * T - 1);
            re_calc(l_0, r_0);
            if(l1 <= r1)
            {
                for(int j = l1; j < r1; j += T)
                {
                    int h1 = upd[j / T];
                    upd[j / T] += x;
                    upd[j / T] = min(upd[j / T], n);
                    if(h1 < T)
                    {
                        re_calc(j, j + T - 1);
                    }
                }
            }
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int it1 = 0, it2 = 0;
           int f1 = u, f2 = v;
            vec1.push_back(f1);
            while(f1 != 0)
            {
                vec1[it1++] = (f1);
                f1 = nxt[f1];
                vec1[it1++] = (f1);
                f1 = max(0, a[f1] - upd[f1 / T]);
            }
            vec1[it1++] = (f1);
            vec2[it2++] = (f2);
            while(f2 != 0)
            {
                vec2[it2++] = (f2);
                f2 = nxt[f2];
                vec2[it2++] = (f2);
                f2 = max(0, a[f2] - upd[f2 / T]);
            }
            vec2[it2++] = (f2);
            int it = 0;
            int v1, u1;
            for(int j = 0; j < it1; j++)
            {
                while(it < it2 && vec2[it] > vec1[j])
                {
                    it++;
                }
                if(it < it2 && vec2[it] == vec1[j])
                {
                    if(it == 0 || j == 0)
                    {
                        u1 = v1 = vec2[it];
                    }
                    else
                    {
                        v1 = vec2[it - 1];
                        u1 = vec1[j - 1];
                    }
                    break;
                }
            }
            while(v1 != u1)
            {
                if(v1 > u1)
                {
                    v1 = max(0, a[v1] - upd[v1 / T]);
                }
                else
                {
                    u1 = max(0, a[u1] - upd[u1 / T]);
                }
            }
            cout << u1 + 1 << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(0); \
             cout.tie(0) \

#define pii pair<int, int>
#define ll long long



vector<ll> s, p;


struct ych
    {
    ll val;

    ych (int val_) :
        val (val_) {}

    ych () :
        val (0) {}

    operator< (ych over)
        {
        return p[val] < p[over.val];
        }
    };
vector<ych> c;

long long a, b, n, m, k, tmp, ans = 0;


int main ()
    {
    FAST;

    cin >> n >> m >> k;

    s.resize(n);
    p.resize(n);
    c.resize(k);

    vector<vector<ych> > sch (m);


    for (int i = 0; i < n; ++i)
        {
        cin >> p[i];
        }

    for (int i = 0; i < n; ++i)
        {
        cin >> s[i];
        s[i]--;

        sch[s[i]].push_back(i);
        }

    for (int i = 0; i < k; ++i)
        {
        cin >> c[i].val;
        c[i].val--;
        }

    for (int i = 0; i < m; ++i)
        {
        sort(sch[i].begin(), sch[i].end());
        }


    for (int i = 0; i < m; ++i)
        {
        for (int j = sch[i].size()-2; j >= 0; --j)
            {
            for (int l = 0; l < c.size(); ++l)
                {
                if (sch[i][j].val == c[l].val) ++ans;
                }
            }
        }

    cout << ans;
    }
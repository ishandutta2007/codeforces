#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<int> a;
vector<int> c;
vector<pair<int, int>> c_;

long long b, k, n, m, tmp, ans = 0;


//int dt[1e6+7];


int main()
    {
    FAST;


    cin >> n >> m;

    a.resize(n);
    c.resize(n);
    c_.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        {
        cin >> c[i];
        c_[i].first = c[i];
        c_[i].second = i;
        }

    sort(c_.begin(), c_.end());

    int cur_min = 0;


    for (int i = 0; i < m; i++)
        {
        ans = 0;
        int t, d;
        cin >> t >> d;
        --t;

        long long to_buy = min(d, a[t]);
        d-= to_buy;
        a[t]-= to_buy;
        ans+= to_buy*c[t];

        while (d > 0 && cur_min < n)
            {
            to_buy = min(d, a[c_[cur_min].second]);
            d-= to_buy;
            a[c_[cur_min].second]-= to_buy;
            ans+= to_buy*c[c_[cur_min].second];


            if (a[c_[cur_min].second] == 0) ++cur_min;
            }

        if (d > 0) cout << 0 << endl;
        else cout << ans << endl;
        }



    return 0;
    }
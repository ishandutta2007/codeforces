#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<vector<long long>> data;
vector<long long> as;

set<vector<long long>> baned;
set<vector<long long>> checked;

long long a, b, k, n, m, tmp, ans = 0;

long long GetMax(vector<long long> dt)
{
    if (checked.count(dt))
        return 0;
    checked.insert(dt);

            //cout << -1 << " " << ans << endl;
    if (!baned.count(dt))
    {

            //cout << -1 << " " << ans << endl;
        long long val = 0;
        for (int i = 0; i < dt.size(); ++i)
        {
            val += ::data[i][dt[i]];
        }
        if (val >= ans)
        {
            //cout << val << " " << ans << endl;
            ans = val;
            as = dt;
        }
        return val;
    }

    long long val = 0;
    for (int i = 0; i < dt.size(); ++i)
    {
        if (dt[i] > 0)
        {
            dt[i]--;
            val = max(val, GetMax(dt));
            dt[i]++;
        }
    }
    return val;
}



int solve()
{
    cin >> n;

    ::data.resize(n);
    ::as.resize(n);

    vector<long long> base(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        base[i] = tmp-1;
        ::data[i].resize(tmp);
        for (int j = 0; j < tmp; ++j)
        {
            cin >> ::data[i][j];
        }
    }

    cin >> m;
    vector<long long> tm(n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tm[j];
            tm[j]--;
        }
        ::baned.insert(tm);
    }

    GetMax(base);


    for (int i = 0; i < n; ++i)
    {
        cout << as[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}


int main()
{
    FAST;

    solve();


    return 0;
}
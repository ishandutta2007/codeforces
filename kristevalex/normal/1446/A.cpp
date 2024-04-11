#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

#define pii pair<int, int>

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


int solve()
{
    cin >> n >> m;

    vector<pii> data(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i].first;
        data[i].second = i+1;
    }

    sort(data.begin(), data.end());

    ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (data[i].first >= (m+1) / 2 && data[i].first <= m)
        {
            cout << "1\n" << data[i].second << endl;
            return 0;
        }
        ans += data[i].first;
        if (ans >= (m+1)/2 && ans <= m)
        {
            cout << i+1 << endl;
            for (int j = 0; j <= i; ++j)
            {
                cout << data[j].second << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}


int main()
{
    FAST;

    cin >> k;

    while(k--)
        solve();




    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0, t;

void solve()
{
    cin >> n >> m;
    vector<std::string> data(n);
    vector<pair<int, int>> as;

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (data[i][j] == '1')
            {
                int dn = 1;
                if (i == n-1)
                    dn = -1;
                int dm = 1;
                if (j == m-1)
                    dm = -1;

                as.push_back({i   , j   });
                as.push_back({i+dn, j   });
                as.push_back({i+dn, j+dm});

                as.push_back({i   , j   });
                as.push_back({i   , j+dm});
                as.push_back({i+dn, j+dm});

                as.push_back({i   , j+dm});
                as.push_back({i+dn, j   });
                as.push_back({i   , j   });

            }
        }
    }

    cout << as.size()/3 << endl;

    for (int i = 0; i < as.size(); ++i)
    {
        cout << as[i].first + 1 << " " << as[i].second + 1 << " ";
        if(i%3 == 2)
            cout << endl;
    }
}


int main()
{
    FAST;

    cin >> t;

    while(t--)
        solve();

    return 0;
}
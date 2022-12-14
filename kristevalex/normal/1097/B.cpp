#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    int dt_old [360] = {};
    int dt [360] = {};

    dt[0] = 1;

    cin >> n;

    bool ok = false;
    for (int i = 1; i <= n; i++)
        {
        cin >> tmp;

        for (int j = 0; j < 360; j++)
            {
            dt_old[j] = dt[j];
            }

        for (int j = 0; j < 360; j++)
            {
            if (dt_old[j] == i)
                {
                dt[(j+tmp)%360] = i+1;
                dt[(j-tmp + 360)%360] = i+1;
                }
            }
        }




    if (dt[0] == n+1) cout << "YES";
    else cout << "NO";

    return 0;
    }
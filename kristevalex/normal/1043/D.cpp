#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m;

    vector<vector<long long>> data(n, vector<long long> (m));

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            {cin >> data[i][j];   --(data[i][j]);}

    vector<long long> fixed (n, -1);
    vector<long long> sums (n, 1);

    for (int i = 1; i < n; i++)
        {
        fixed[data[i][0]] = data[i-1][0];
        }

    for (int j = 1; j < m; j++)
        {
        fixed[data[0][j]] = -1;
        for (int i = 1; i < n; i++)
            {
            if (fixed[data[i][j]] != data[i-1][j]) fixed[data[i][j]] = -1;
            }
        }


    for (int i = 1; i < n; i++)
        {
        if (fixed[data[i][0]] != -1)
            {
            sums[data[i][0]] = 1 + sums[data[i-1][0]];
            }
        }

    for (int i = 0; i < n; i++)
        {
        ans+= sums[i];
        }

    cout << ans;

    return 0;
    }
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    vector<vector<int>> d (n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> d[i][j];
            if ((d[i][j] + i + j)%2 == 1)
                d[i][j]++;
        }
    }

    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;



}

int main()
{
    FAST;

    cin >> k;


    while(k--)
        solve();





    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<string> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 1; i < n-1; i++)
        {
        for (int j = 1; j < n-1; j++)
            {
            //cout << i << " " << j << endl;
            if (data[i  ][j  ] == 'X' &&
                data[i+1][j+1] == 'X' &&
                data[i-1][j-1] == 'X' &&
                data[i-1][j+1] == 'X' &&
                data[i+1][j-1] == 'X') ++ans;
            }
        }


    cout << ans;

    return 0;
    }
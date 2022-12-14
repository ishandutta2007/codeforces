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


    cin >> n;

    data.resize(200);

    for (int i = 0; i < n; i++)
        {
        cin >> a;
        for (int j = 0; j < a; j++)
            {
            cin >> b;
            data[b]++;
            }
        }



    for (int i = 0; i < 150; i++)
        {
        if (data[i] == n) cout << i << " ";
        }

    return 0;
    }
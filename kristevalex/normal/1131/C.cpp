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

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());

    vector<int> ansers(n, 0);



    for (int i = 0; i < n; i++)
        {
        if (i%2 == 0)
            {
            ansers[i/2] = data[i];
            }
        else
            {
            ansers[n-1-i/2] = data[i];
            }
        }


    for (int i = 0; i < n; i++)
        {
        cout << ansers[i] << " ";
        }

    return 0;
    }
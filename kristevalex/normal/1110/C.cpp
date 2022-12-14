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

    long long n_2[30] = {};
    n_2[0] = 1;
    for (int i = 1; i < 28; i++)
        {
        n_2[i] = n_2[i-1]*2;
        }


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> a;

        tmp = 0;
        while (a > n_2[tmp] - 1) ++tmp;

        //cout << tmp << ' ';

        if (a != n_2[tmp] - 1)
            {
            cout << n_2[tmp]-1 << endl;
            continue;
            }
        bool ok = false;

        long long SQRT = sqrt(n_2[tmp] - 1);
        for (int j = 2; j <= SQRT; j++)
            {
            if ((n_2[tmp] - 1)%j == 0)
                {
                cout << (n_2[tmp] - 1)/j << endl;
                ok = true;
                break;
                }
            }

        if (!ok) cout << 1 << endl;
        }








    return 0;
    }
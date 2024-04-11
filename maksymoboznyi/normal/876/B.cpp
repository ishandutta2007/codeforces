#include <bits/stdc++.h>
#define int long long
#define small -2000000000000000000
#define big 2000000000000000000
#define pb push_back
using namespace std;

int c = -1, n, k, m, a[1000005], kol[1000005];

signed main()
{
    cin >> n >> k >> m;
    for (int i = 0; i <n; i++)
    {
        cin >> a[i];
        kol[a[i]%m]++;
    }
    for (int i = 0; i <m; i++)
        if (kol[i] >= k)
        {
            c = i;
            break;
        }
    if (c == -1)
        cout << "No";
    else
    {
       int kol = 0;
       cout << "Yes\n";
       for (int i = 0; i <n; i++)
            if (a[i] % m == c && kol < k)
            {
                cout << a[i] << ' ';
                kol++;
            }
    }
    return 0;
}
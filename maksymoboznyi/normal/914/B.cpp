#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6+6;

ll n, kol[N], a[N], ma, kma;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], kol[a[i]]++;
    sort(a+1, a+n+1);
    kma = 1;
    if (a[n-1] != a[n])
    {
        cout << "Conan";
        return 0;
    }
    for (int i = 1; i < n; i++)
        if (a[i] == a[n])
            kma++;
    if (kma % 2 == 1)
    {
        cout << "Conan";
        return 0;
    }
    for (int i = 1; i <= 1000000; i++)
        if (kol[i] % 2 == 1)
        {
            cout << "Conan";
            return 0;
        }
    cout << "Agasa";
    return 0;
}
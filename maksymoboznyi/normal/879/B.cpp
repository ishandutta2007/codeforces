#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3+5;
ll n, k, a[N];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k >= n-1)
    {
        int pma = 1;
        for (int i = 2; i <= n; i++)
            if (a[pma] < a[i])
                pma = i;
        cout << a[pma];
    }else
    {
        for (int i = 1; i <= n; i++)
            a[i+n] = a[i];
        for (int i = 1; i <= n; i++)
        {
            int kol = 0;
            for (int j = i+1; a[j] != a[i]; j++)
                if (a[j] < a[i])
                    kol++;
                else
                    break;
            if ((i == 1 && kol >= k)||(i != 1 && kol >= k-1 && a[i] > a[i-1]))
            {
                cout << a[i];
                return 0;
            }
        }
    }
    return 0;
}
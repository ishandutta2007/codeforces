#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define M 1000000007;
using namespace std;
const int N = 2e5+6;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int k1 = 0, k2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            k1++;
        else
            k2++;
    }
    if (k1 < k2)
        cout << k1;
    if (k1 == k2)
        cout << k2;
    if (k1 > k2)
        cout << k2 + (k1-k2)/3;
    return 0;
}
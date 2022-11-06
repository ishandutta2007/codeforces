#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back

using namespace std;
int main()
{
    ll n, k, t;
    cin >> n >> k >> t;
    if (t <= k)
    {
        cout << t;
        return 0;
    }
    if (t <= n)
    cout << k;
    else
        cout << k - (t-n);
    return 0;
}
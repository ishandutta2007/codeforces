#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 5e5+10;

int lon[N], a[N], n;

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans = 0, pos = 0;
    for (int i = 1; i <= n; i++)
        lon[a[i]] = i;
    for (int i = 0; i <= 2e5; i++)
        if (n+1- lon[i] > ans && lon[i] > 0)
        {
            ans = n+1-lon[i];
            pos = i;
        }
    cout << pos;
    return 0;
}
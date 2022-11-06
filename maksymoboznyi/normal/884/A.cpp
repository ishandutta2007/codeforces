#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5;
ll n, a[N], t, now = 0;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        now += 86400-a[i];
        if (now >= t) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
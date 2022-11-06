#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3000;
ll n, k, p, a[N], b[N], ans = 999999999999999;

int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    sort(b+1, b+k+1);
    for (int start = 1; start <= k-n+1; start++)
    {
        ll cans = 0;
        for (int i = start; i < start+n; i++)
            cans = max(abs(a[i-start+1] - b[i]) + abs(b[i] -p), cans);
        ans = min(ans, cans);
    }
    cout << ans;
    return 0;
}
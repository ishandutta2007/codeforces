#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 2e18;

long long n, k;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    long long ans = 0;
    ans += (n * 2 - 1) / k + 1;
    ans += (n * 5 - 1) / k + 1;
    ans += (n * 8 - 1) / k + 1;
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 5e5+5;
const long long inf = 2e18;

long long n;

signed main()
{
    cin >> n;
    ll ans = 0;
    ans += n/100;
    n %= 100;
    ans += n/20;
    n %= 20;
    ans += n/10;
    n %= 10;
    ans += n/5;
    n %= 5;
    ans += n;
    cout << ans;
    return 0;
}
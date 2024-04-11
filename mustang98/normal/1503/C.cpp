#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;


int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    vector<pair<ll, ll>> v;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        ans += b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    ll mx = v[0].F + v[0].S;
    for (int i = 1; i < n; ++i) {
        ans += max(0LL, v[i].F - mx);
        mx = max(mx, v[i].F + v[i].S);
    }
    cout << ans << endl;
    return 0;
}
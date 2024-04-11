#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

ll l1, r1, t1;
ll l2, r2, t2;


ll solve() {
    ll gc = __gcd(t1, t2);
    ll dl = (l2 + inf * t2 - l1) % t1;
    ll a = dl % gc;
    ll ans = min(r1 - l1 - a + 1, r2 - l2 + 1);
    return max(ans, 0LL);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> l1 >> r1 >> t1;
    cin >> l2 >> r2 >> t2;
    ll ans1 = solve();
    swap(l1, l2);
    swap(r1, r2);
    swap(t1, t2);
    ll ans2 = solve();
    cout << max(ans1, ans2);
    return 0;
}
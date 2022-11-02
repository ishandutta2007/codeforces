#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define MAX 100000

typedef unsigned long long ll;

ll n, m = 0;
ll a[MAX + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        a[k]++;
        m = max(m, k);
    }

    ll prevprev = 0;
    ll prev = a[1];
    for (ll i = 2; i <= m; i++) {
        ll next = max(prevprev + a[i] * i, prev);
        prevprev = prev;
        prev = next;
    }
    cout << prev << endl;
    return 0;
}
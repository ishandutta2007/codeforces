#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "0 0";
        return 0;
    }

    n--;

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (3 * ll(mid) * (mid + 1) <= n) lo = mid;
        else hi = mid - 1;
    }

    int k = lo + 1;
    ll x = 2 * k, y = 0;

    n -= 3 * ll(lo) * (lo + 1) - 1;

    if (n <= k) {
        x -= n;
        y += 2 * n;
        cout << x << ' ' << y;
        return 0;
    } n -= k, x -= k, y += 2 * k;

    if (n <= k) {
        x -= 2 * n;
        cout << x << ' ' << y;
        return 0;
    } n -= k, x -= 2 * k;

    if (n <= k) {
        x -= n;
        y -= 2 * n;
        cout << x << ' ' << y;
        return 0;
    } n -= k, x -= k, y -= 2 * k;

    if (n <= k) {
        x += n;
        y -= 2 * n;
        cout << x << ' ' << y;
        return 0;
    } n -= k, x += k, y -= 2 * k;

    if (n <= k) {
        x += 2 * n;
        cout << x << ' ' << y;
        return 0;
    } n -= k, x += 2 * k;

    if (n <= k) {
        x += n;
        y += 2 * n;
        cout << x << ' ' << y;
        return 0;
    }

    assert(0);
}
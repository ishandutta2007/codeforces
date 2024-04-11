#include <bits/stdc++.h>

using namespace std;

long long la, ra, ta, lb, rb, tb, d;

long long cal(long long x, long long y, long long u, long long v) {
    return max(0LL, min(y, v) - max(x, u) + 1);
}
long long f(long long k) {
    return cal(la + k * d, ra + k * d, lb, rb);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    if (la > lb) swap(la, lb), swap(ra, rb), swap(ta, tb);
    d = __gcd(ta, tb);
    long long step = (lb - la) / d;
    cout << max(f(step), f(step + 1)) << endl;
    return 0;
}
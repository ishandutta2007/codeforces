#include <iostream>

using namespace std;

typedef long long ll;

// a <= t * k <= b

// a <= t * k
// t * k <= b

// t >= a / k
// t <= b / k

ll up(ll u, ll v) {
if(v < 0) v *= -1, u *= -1;
if(u > 0) return u / v + (u % v > 0);
else return u / v;
}

ll down(ll u, ll v) {
if(v < 0) v *= -1, u *= -1;
if(u > 0) return u / v;
else return u / v - (u % v < 0);
}

int main() {

ll k, a, b;

cin >> k >> a >> b;

ll l, r;

r = down(b, k);
l = up(a, k);

cout << max(0ll, r - l + 1) << '\n';

return 0;
}
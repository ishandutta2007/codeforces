#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll get(ll iter, ll len, ll k) {
    // 1 .. len / 2 | len / 2 + 1 | len / 2 + 2 .. len
    if(k == len / 2 + 1) {
        return iter + 1;
    }else if(k < len / 2 + 1) {
        return get(iter - 1, len / 2, k);
    }else {
        return get(iter - 1, len / 2, k - (len / 2 + 2) + 1);
    }
}

int main() {

    ll len = 1;

    ll n, k;

    cin >> n >> k;

    for(int i = 0;i < n;i++) {
        len = len + len + 1;
    }

    cout << get(n, len, k) << "\n";

    return 0;
}
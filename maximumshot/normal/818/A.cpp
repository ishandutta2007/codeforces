#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll n, k;

    cin >> n >> k;

    ll x = n / (2 * (1 + k));

    cout << x << " " << k * x << " " << n - (k + 1) * x << "\n";

    return 0;
}
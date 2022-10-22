#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n, k;

    cin >> n >> k;

    vec< ll > a;

    a.reserve(1e6);

    for(ll x = 1;x * x <= n;x++) {
        if(n % x == 0) {
            a.push_back(x);
            a.push_back(n / x);
        }
    }

    sort(ALL(a));
    a.resize(unique(ALL(a)) - a.begin());

    if(k > (int)a.size()) {
        cout << -1 << "\n";
    }else {
        cout << a[k - 1] << "\n";
    }

    return 0;
}
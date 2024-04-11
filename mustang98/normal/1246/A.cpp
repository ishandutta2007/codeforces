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

ll n, p;

bool can(ll a, ll k) {
    if (a <= 0) {
        return 0;
    }
    int c1 = __builtin_popcountll(a);
    if (k < c1 || k > a) {
        return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> p;
    for (int k = 1; k <= 50000; ++k) {
        ll val = n - k * p;
        if (can(val, k)) {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
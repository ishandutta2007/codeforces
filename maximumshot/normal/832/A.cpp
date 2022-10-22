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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n, k;

    cin >> n >> k;

    ll cnt = n / k;

    if(cnt % 2) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}
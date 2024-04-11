#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n;

    cin >> n;

    ll mx = 0;

    for(int i = 0;i < 40;i++) {
        if((1ll << i) & n) {
            mx = i;
        }
    }

    cout << mx + 1 << "\n";

    return 0;
}
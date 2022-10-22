#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    int res = 0;

    for(int x = 0;x <= a;x++) {
        if(2 * x <= b && 4 * x <= c) {
            res = max(res, 7 * x);
        }
    }

    cout << res << "\n";

    return 0;
}
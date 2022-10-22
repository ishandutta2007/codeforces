#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    int A = 1;
    int B = n;

    for(int x = 2;x * x <= n;x++) {
        if(n % x) continue;
        int y = n / x;
        if(x > y) break;
        if(x - y < B - A) {
            A = x;
            B = y;
        }
    }

    cout << A << " " << B << "\n";

    return 0;
}
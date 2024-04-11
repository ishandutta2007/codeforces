#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    cin >> n;

    if(n > 1) {
        cout << n << " " << n + 1 << " " << n * (n + 1) << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
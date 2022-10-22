#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3e5 + 5;


int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int l, r;

    cin >> l >> r;

    if(l == r) {
        cout << l << "\n";
    }else {
        cout << "2\n";
    }

    return 0;
}
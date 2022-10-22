#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int a[N];
int b[N];

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
    }

    if(a[1] != b[1] || a[n] != b[n]) {
        puts("No");
        return 0;
    }

    for(int i = 1;i < n;i++) {
        a[i] = a[i + 1] - a[i];
        b[i] = b[i + 1] - b[i];
    }

    sort(a + 1, a + n);
    sort(b + 1,  b + n);

    for(int i = 1;i < n;i++) {
        if(a[i] != b[i]) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}
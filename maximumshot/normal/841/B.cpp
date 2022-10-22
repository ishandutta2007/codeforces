#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, x;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &x);
        if(x % 2) {
            puts("First");
            return 0;
        }
    }

    puts("Second");

    return 0;
}
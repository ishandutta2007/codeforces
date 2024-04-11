#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    scanf("%d", &n);

    int x1, y1;
    int x2, y2;

    printf("YES\n");

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 = (x1 % 2 + 2) % 2;
        y1 = (y1 % 2 + 2) % 2;
        printf("%d\n", x1 * 2 + y1 + 1);
    }

    return 0;
}
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

    // 8 4 2 6

    int mas[4] = {8, 4, 2, 6};
    int n;

    scanf("%d", &n);

    printf("%d\n", n == 0 ? 1 : mas[(n - 1) % 4]);

    return 0;
}
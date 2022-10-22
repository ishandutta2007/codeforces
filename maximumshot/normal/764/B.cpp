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

    vec< int > a(n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0;i < n / 2;i += 2) {
        swap(a[i], a[n - 1 - i]);
    }

    for(int i = 0;i < n;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
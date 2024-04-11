#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    scanf("%d", &n);

    vec< int > a(n);
    vec< int > res(n, inf);

    for(int last = -inf, i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        if(a[i] == 0) last = i;
        res[i] = i - last;
    }

    for(int last = inf, i = n - 1;i >= 0;i--) {
        if(a[i] == 0) last = i;
        res[i] = min(res[i], last - i);
    }

    for(int i = 0;i < n;i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}
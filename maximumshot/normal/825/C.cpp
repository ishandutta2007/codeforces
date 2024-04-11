#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

int n, k;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int ptr = 0, cnt = 0;
    int res = 0;

    while(ptr < n) {
        // 1 .. 2 * k
        while(ptr < n && a[ptr] <= 2 * k) ptr++;
        if(ptr == n) break;
        if(ptr > 0 && k < a[ptr - 1]) {
            k = a[ptr - 1];
        }else {
            res++;
            k *= 2;
        }
    }

    printf("%d\n", res);

    return 0;
}
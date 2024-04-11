#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, s;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &s);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    int L = 0;
    int R = 0;

    for(int i = 0;i < n;i++) {
        if(a[i] <= s) {
            L++;
        }else {
            R++;
        }
    }

    ll res = 0;

    if(L < (n + 1) / 2) {
        for(int i = 0;i <= n / 2;i++) {
            if(a[i] > s) res += a[i] - s;
        }
    }else {
        for(int i = n / 2;i < n;i++) {
            if(a[i] < s) res += s - a[i];
        }
    }

    printf("%lld\n", res);

    return 0;
}
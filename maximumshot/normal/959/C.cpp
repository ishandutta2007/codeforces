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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    if(n <= 5) {
        puts("-1");
    }else {
        puts("1 2");
        for(int i = 3;i <= n;i++) {
            printf("%d %d\n", 1 + (i & 1), i);
        }
    }

    for(int i = 1;i < n;i++) {
        printf("%d %d\n", i, i + 1);
    }

    return 0;
}
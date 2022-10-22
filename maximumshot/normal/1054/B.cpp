#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int a[N];
int u[N], ptr = 0;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    if(a[1] > 0) {
        puts("1");
        return 0;
    }

    u[0] = 1;
    ptr = 0;

    for(int i = 2;i <= n;i++) {
        while(u[ptr]) ptr++; ptr--;
        if(ptr < a[i] - 1) {
            printf("%d\n", i);
            return 0;
        }
        u[a[i]] = 1;
    }

    puts("-1");

    return 0;
}
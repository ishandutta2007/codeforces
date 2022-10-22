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

const int N = 2e5 + 5;

int n;
int a[N];
int u[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        u[a[i]] = 1;
    }

    for(int l = 1, x, i = 0;i < n;i++) {
        scanf("%d", &x);
        if(!u[x]) {
            printf("0 ");
            continue;
        }
        int r = 0;
        while(u[x]) {
            u[a[l++]] = 0;
            r++;
        }
        printf("%d ", r);
    }

    return 0;
}
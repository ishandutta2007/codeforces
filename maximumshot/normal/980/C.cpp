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

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > gr(256, -1);

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        if(gr[x] == -1) {
            int y = x;
            while(y >= 0 && x - y + 1 <= k && gr[y] == -1) y--;
            y++;
            if(y > 0 && gr[y - 1] != -1 && x - gr[y - 1] + 1 <= k) y = gr[y - 1];
            printf("%d ", y);
            for(int q = y;q <= x;q++) {
                gr[q] = y;
            }
        }else {
            printf("%d ", gr[x]);
        }
    }

    printf("\n");

    return 0;
}
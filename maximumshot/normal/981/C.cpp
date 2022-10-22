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

    vec< int > deg(n + 1);

    for(int u, v, i = 2;i <= n;i++) {
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
    }

    int mx = 1;
    vec< int > leafs;

    for(int i = 1;i <= n;i++) {
        if(deg[i] == 1) leafs.push_back(i);
        if(deg[mx] < deg[i]) mx = i;
    }

    if((int)leafs.size() == 2) {
        puts("Yes");
        printf("1\n%d %d\n", leafs.front(), leafs.back());
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        if(i == mx) continue;
        if(deg[i] > 2) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    printf("%d\n", (int)leafs.size());

    for(int v : leafs) {
        printf("%d %d\n", v, mx);
    }

    return 0;
}
#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vec< int > t(n + 1);
    vec< int > c(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &t[i]);
        c[t[i]]++;
    }

    printf("%d\n", count(ALL(c), 0));

    return 0;
}
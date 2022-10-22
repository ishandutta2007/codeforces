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

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    // 2 * x <= N
    // 0 <= x <= N / 2

    // N / 2 + 1

    int a;

    scanf("%d", &a);

    if(a == 1) {
        printf("1 1\n1\n");
        return 0;
    }

    int N = (a - 1) * 2;

    printf("%d 2\n1 2\n", N);

    return 0;
}
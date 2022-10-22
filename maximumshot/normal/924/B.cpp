#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, U;
int E[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &U);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &E[i]);
    }

    int any = 0;
    double res = -1e9;

    for(int k = 1, i = 1;i <= n;i++) {
        if(k < i) k = i;
        while(k < n && E[k + 1] - E[i] <= U) k++;
        if(i + 1 < k) {
            any = 1;
            res = max(res, 1.0 * (E[k] - E[i + 1]) / (E[k] - E[i]));
        }
    }

    if(any) {
        printf("%.10lf\n", res);
    }else {
        puts("-1");
    }

    return 0;
}
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

int calc(const vec< int > &p) {
    int n = (int)p.size();
    vec< int > dp(n);
    for(int i = 0;i < n;i++ ) {
        dp[i] = 1;
        for(int j = 0;j < i;j++) {
            if(p[i] > p[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(ALL(dp));
}

vec< int > fnd(int n) {
    vec< int > p(n);
    for(int i = 0;i < n;i++) p[i] = i;
    vec< int > best;
    int res = inf;
    do{
        int tmp = 0;
        tmp += calc(p);
        reverse(ALL(p));
        tmp += calc(p);
        reverse(ALL(p));
        if(res > tmp) {
            res = tmp;
            best = p;
        }
    }while(next_permutation(ALL(p)));
    return best;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    int res = inf, best = -1;

    for(int c = 1;c <= n;c++) {
        int tmp = c + (n + c - 1) / c;
        if(res > tmp) {
            res = tmp;
            best = c;
        }
    }

    for(int i = 1;i <= n;) {
        int j = min(n, i + best - 1);
        for(int q = j;q >= i;q--) {
            printf("%d ", q);
        }
        i = j + 1;
    }

    printf("\n");

    return 0;
}
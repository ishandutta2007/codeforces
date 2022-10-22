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

    vec< int > a(n);

    int mn = inf;
    for(int &x : a) scanf("%d", &x), mn = min(mn, x);
    for(int &x : a) x -= n * (mn / n);

    int cur = 0;

    for(int i = 0;;i = (i + 1) % n) {
        if(cur >= a[i]) {
            printf("%d\n", i + 1);
            return 0;
        }else {
            cur++;
        }
    }

    return 0;
}
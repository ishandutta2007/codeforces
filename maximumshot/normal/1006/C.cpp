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

const int N = 2e5 + 5;

int n;
int d[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) scanf("%d", &d[i]);

    ll s1 = 0;
    ll s2 = 0;
    ll res = 0;

    for(int j = n + 1, i = 1;i <= n;i++) {
        s1 += d[i];
        while(j - 1 > i && s2 < s1) s2 += d[--j];
        if(s1 == s2 && s1 > res) res = s1;
    }

    printf("%lld\n", res);

    return 0;
}
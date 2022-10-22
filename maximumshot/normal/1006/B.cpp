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

const int N = 2005;

int n, k;
pii a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    sort(a + 1, a + k + 1, [](const pii &p1, const pii &p2){
        return p1.second < p2.second;
    });

    int res = 0;

    for(int i = 1;i <= k;i++) res += a[i].first;

    printf("%d\n", res);

    for(int it = 1;it <= k;it++) {
        int le, ri;
        le = a[it - 1].second + 1;
        ri = a[it].second;
        if(it == k) ri = n;
        printf("%d ", ri - le + 1);
    }

    printf("\n");



    return 0;
}
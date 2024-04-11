#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< int > a(n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0;i < n;i++) {
        if(i + 1 < n) printf("%d ", a[i] + a[i + 1]);
        else printf("%d ", a[i]);
    }
    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}
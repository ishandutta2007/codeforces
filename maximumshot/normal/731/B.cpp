#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

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

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0;i < n;i++) {
        if(a[i] % 2) {
            if(i + 1 == n || !a[i + 1]) {
                printf("NO\n");
                return true;
            }else {
                a[i + 1]--;
            }
        }
    }

    printf("YES\n");
    
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
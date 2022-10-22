#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;

    scanf("%d", &n);

    vec< int > a(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    sort(ALL(a));

    int q;
    scanf("%d", &q);

    for(int x, i = 0;i < q;i++) {
        scanf("%d", &x);
        printf("%d\n", upper_bound(ALL(a), x) - a.begin());
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, b, d;

    scanf("%d %d %d", &n, &b, &d);

    int res = 0;
    int sum = 0;

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        if(x > b) continue;
        sum += x;
        if(sum > d) res++, sum = 0;
    }

    printf("%d\n", res);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
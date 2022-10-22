#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

double const pi = acos(-1.0);
double const eps = 1e-9;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< int > a(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]), a[i] -= (n - 1 - i);

    sort(ALL(a));

    for(int i = 0;i < n;i++) {
        a[i] += (n - 1 - i);
    }

    for(int i = 0;i + 1 < n;i++) {
        if(a[i] > a[i + 1]) {
            printf(":(\n");
            return true;
        }
    }

    for(int i = 0;i < n;i++) printf("%d ", a[i]);
    printf("\n");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
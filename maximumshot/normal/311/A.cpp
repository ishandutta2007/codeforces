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

    int n, k;

    cin >> n >> k;

    if(n * (n - 1) / 2 <= k) {
        printf("no solution\n");
        return true;
    }else {
        for(int i = 0;i < n;i++) {
            printf("0 %d\n", i);
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
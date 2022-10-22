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

    int last = -inf - inf;

    int n, c;
    cin >> n >> c;

    int res = 0;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if(last + c < x) res = 1;
        else res++;
        last = x;
    }

    cout << res << '\n';

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
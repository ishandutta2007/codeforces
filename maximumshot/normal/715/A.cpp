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

ll my_sqrt(ll x) {
    ll y = (ll)sqrt(ld(x));
    while((y + 1) * (y + 1) <= x) y++;
    if(y * y == x) return y;
    else return -1;
}

bool solve() {

    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll x = 2, t;

    for(int i = 1;i <= n;i++) {
        t = 1ll * i * (i + 1) * (i + 1) - x / i;
        cout << t << '\n';
        x = 1ll * i * (i + 1);
    }

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
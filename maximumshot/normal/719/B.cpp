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
    cin >> n;

    string s;
    cin >> s;

    int res = inf;

    for(int iter = 0;iter < 2;iter++) {
        int r = 0, b = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] == 'r' && i % 2 != iter) r++;
            else if(s[i] == 'b' && i % 2 == iter) b++;
        }
        res = min(res, max(r, b));
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
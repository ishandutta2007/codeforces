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

    int n, m;
    cin >> n >> m;

    vec< vec< int > > a(n, vec< int >(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }

    for(int x = 0;x < m;x++) {
        for(int y = x;y < m;y++) {
            for(int i = 0;i < n;i++) {
                swap(a[i][x], a[i][y]);
            }
            int ok = 1;
            for(int iter = 0;iter < n;iter++) {
                int cnt = 0;
                for(int i = 0;i < m;i++) {
                    if(a[iter][i] != i + 1) cnt++;
                }
                if(cnt > 2) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                cout << "YES\n";
                return true;
            }
            for(int i = 0;i < n;i++) {
                swap(a[i][x], a[i][y]);
            }
        }
    }

    cout << "NO\n";

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
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    vec< string > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    int tot = 0;

    string tmp = "RGB";

    int W = -1;
    int H = -1;

    for(char t : tmp) {
        int le = inf;
        int ri = -inf;
        int up = inf;
        int dn = -inf;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(a[i][j] == t) {
                    le = min(le, j);
                    ri = max(ri, j);
                    up = min(up, i);
                    dn = max(dn, i);
                }
            }
        }
        if(le == inf) {
            cout << "NO\n";
            return 0;
        }
        tot += (ri - le + 1) * (dn - up + 1);
        if(W != -1 && (ri - le + 1) != W) {
            cout << "NO\n";
            return 0;
        }
        if(H != -1 && (dn - up + 1) != H) {
            cout << "NO\n";
            return 0;
        }
        W = ri - le + 1;
        H = dn - up + 1;
    }

    if(tot == n * m) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}
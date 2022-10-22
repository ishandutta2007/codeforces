#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    vec< int > a(n), b(m);

    int xr = 0;
    for(int i = 0;i < n;i++) cin >> a[i], xr ^= a[i];
    for(int j = 0;j < m;j++) cin >> b[j], xr ^= b[j];

    if(xr) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vec< vec< int > > mat(n, vec< int >(m));

    for(int x = 0;x <= 30;x++) {
        int I = -1, cnti = 0;
        int J = -1, cntj = 0;
        for(int i = 0;i < n;i++) if((1 << x) & a[i]) I = i, cnti++;
        for(int j = 0;j < m;j++) if((1 << x) & b[j]) J = j, cntj++;
        for(int i = 0;i < I;i++) {
            if(!((1 << x) & a[i])) continue;
            for(int j = 0;j < J;j++) {
                if(!((1 << x) & b[j])) continue;
                mat[i][j] |= (1 << x);
            }
        }
        if(cnti == 0 && cntj == 0) continue;
        if(cnti == 0) {
            for(int j = 0;j <= J;j++) {
                if((1 << x) & b[j]) {
                    mat[0][j] |= (1 << x);
                }
            }
        }else if(cntj == 0) {
            for(int i = 0;i <= I;i++) {
                if((1 << x) & a[i]) {
                    mat[i][0] |= (1 << x);
                }
            }
        }else {
            if(cnti & 1) {
                for(int j = 0;j <= J;j++) {
                    if((1 << x) & b[j]) mat[I][j] |= (1 << x);
                }
                for(int i = 0;i <= I;i++) {
                    if((1 << x) & a[i]) mat[i][J] |= (1 << x);
                }
            }else {
                mat[I][J] |= (1 << x);
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
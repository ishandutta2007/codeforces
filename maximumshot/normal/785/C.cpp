#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll n, m;

    cin >> n >> m;

    if(m >= n) {
        cout << n << "\n";
    }else {
        ll bl = 0;
        ll br = 2ll * inf;
        ll bm;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(n - m - (bm + 1) * (bm + 2) / 2 <= 0) {
                br = bm;
            }else {
                bl = bm;
            }
        }
        ll I;
        if(bl < br && n - m - (bl + 1) * (bl + 2) / 2 <= 0) {
            I = bl;
        }else {
            I = br;
        }
        cout << m + I + 1 << "\n";
    }

    return 0;
}
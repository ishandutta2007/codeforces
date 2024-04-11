#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, L;

    cin >> n >> L;

    vec< ll > c(31, inf64);

    for(int i = 0;i < n;i++) {
        cin >> c[i];
    }

    for(int i = 1;i <= 30;i++) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }

    ll res = inf64;
    ll cur = 0;

    for(int i = 30;i >= 0;i--) {
        if((1 << i) & L) {
            cur += c[i];
        }else {
            res = min(res, cur + c[i]);
        }
        if(i == 0) {
            res = min(res, cur);
        }
    }

    cout << res << "\n";

    return 0;
}
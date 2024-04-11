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

    int n, k;

    cin >> n >> k;

    cout << "YES\n";

    vec< string > res(4, string(n, '.'));

    if(k % 2) {
        res[1][n / 2] = '#';
        k--;
    }

    int ost = k;

    for(int i = 1;ost > 0;i++) {
        if(n / 2 - i > 0) {
            res[1][n / 2 - i] = res[1][n / 2 + i] = '#';
        }else {
            res[1][n / 2] = res[2][n / 2] = '#';
        }
        ost -= 2;
        if(ost) {
            res[2][n / 2 - i] = res[2][n / 2 + i] = '#';
            ost -= 2;
        }
    }

    for(int i = 0;i < 4;i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
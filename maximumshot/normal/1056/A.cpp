#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 105;

int n;
bitset< N > all;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    all.set();

    for(int i = 0;i < n;i++) {
        bitset< N > tmp;
        int r;
        cin >> r;
        for(int x, j = 0;j < r;j++) {
            cin >> x;
            tmp[x] = 1;
        }
        all &= tmp;
    }

    for(int i = 0;i < N;i++) {
        if(all[i]) {
            cout << i << " ";
        }
    }

    cout << "\n";

    return 0;
}
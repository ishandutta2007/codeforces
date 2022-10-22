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

    int n, k;

    cin >> n >> k;

    int s = 0;
    int x;
    int c = 0;

    for(int i = 1;i <= n;i++) {
        cin >> x;
        if(x >= 8) {
            c += x - 8;
            x = 8;
        }
        s += x;
        if(x < 8) {
            int add = min(8 - x, c);
            s += add;
            c -= add;
        }
        if(s >= k) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
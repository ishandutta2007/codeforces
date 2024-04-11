#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;


int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int a, b;

    cin >> a >> b;

    for(int x = 0, i = 1;;i++, x ^= 1) {
        if(x == 0) {
            if(a >= i) {
                a -= i;
            }else {
                cout << "Vladik\n";
                return 0;
            }
        }else {
            if(b >= i) {
                b -= i;
            }else {
                cout << "Valera\n";
                return 0;
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    vec< ll > f(100);
    f[0] = 1;
    f[1] = 2;
    
    for(int i = 2;i < 100;i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    
    ll n;
    cin >> n;

    for(int i = 0;i < 100;i++) {
        if(f[i] > n) {
            cout << i - 1 << "\n";
            return 0;
        }
    }

    return 0;
}
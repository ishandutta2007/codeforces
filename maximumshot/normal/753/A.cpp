#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    int res = 0;

    vec< int > way;

    for(int i = 1;i <= n;i++) {
        if(n >= i) {
            res++;
            n -= i;
            way.push_back(i);
        }
    }

    way.back() += n;

    cout << res << "\n";

    for(int x : way) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
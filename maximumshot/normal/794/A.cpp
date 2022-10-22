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
//    freopen("input.txt", "r", stdin);
#endif

    int a, b, c;

    cin >> a >> b >> c;

    int n;
    cin >> n;

    int res = 0;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if(x > b && x < c) res++;
    }

    cout << res << "\n";

    return 0;
}
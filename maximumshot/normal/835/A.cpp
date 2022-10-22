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

    int s, v1, v2, t1, t2;

    cin >> s >> v1 >> v2 >> t1 >> t2;

    int r1 = 2 * t1 + s * v1;
    int r2 = 2 * t2 + s * v2;

    if(r1 < r2) {
        cout << "First\n";
    }else if(r1 > r2) {
        cout << "Second\n";
    }else {
        cout << "Friendship\n";
    }

    return 0;
}
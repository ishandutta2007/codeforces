#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline double sqr(double x) {
    return x * x;
}

bool solve() {

    double a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double res;

    for(int i = 0;i < n;i++) {
        double x, y, v;
        cin >> x >> y >> v;
        if(i == 0 || res > sqrt(sqr(x - a) + sqr(y - b)) / v)
            res = sqrt(sqr(x - a) + sqr(y - b)) / v;
    }

    cout << fixed << setprecision(10) << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
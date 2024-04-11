#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    double m;

    cin >> n;
    cin >> m;

    double res;

    for(int i = 0;i < n;i++) {
        double a, b;
        cin >> a >> b;
        if(!i || res > a / b) {
            res = a / b;
        }
    }

    cout.precision(20);
    cout << fixed << res * m << "\n";

    return 0;
}
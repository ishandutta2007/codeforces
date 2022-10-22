#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

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

    int n, d;

    cin >> n >> d;

    vec< int > a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    sort(ALL(a));

    int res = inf;

    for(int i = 0;i < n;i++) {
        for(int j = i;j < n && a[j] - a[i] <= d;j++) {
            res = min(res, i + n - j - 1);
        }
    }

    cout << res << "\n";

    return 0;
}
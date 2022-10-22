#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

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

    vec< int > a = {100, 20, 10, 5, 1};

    int n;

    cin >> n;

    int res = 0;

    for(int x : a) {
        res += n / x;
        n %= x;
    }

    cout << res << "\n";

    return 0;
}
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

    int n;

    cin >> n;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if(x % 2 == 0) x--;
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
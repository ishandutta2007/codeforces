#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    vec< int > a(n), b(10);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for(int x, i = 0;i < 10;i++) {
        cin >> x;
        b[x] = 1;
    }

    for(int i = 0;i < n;i++) {
        if(b[a[i]]) {
            cout << a[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}
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

    int n;

    cin >> n;
    set< int > q;

    int cnt0 = 0;

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if(x) q.insert(x);
    }

    cout << (int)q.size() << "\n";

    return 0;
}
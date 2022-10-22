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

    vec< int > p(n + 1);

    for(int i = 1;i <= n;i++) cin >> p[i];

    for(int i = 1;i <= n;i++) {
        vec< int > used(n + 1);
        int v = i;
        while(!used[v]) used[v] = 1, v = p[v];
        cout << v << " ";
    }

    cout << "\n";

    return 0;
}
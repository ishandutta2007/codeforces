#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 1005;

int n;
vec< int > g[N];

inline bool is_leaf(int v) {
    if(v == 1) return false;
    else return g[v].empty();
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    for(int p, i = 2;i <= n;i++) {
        cin >> p;
        g[p].push_back(i);
    }

    for(int v = 1;v <= n;v++) {
        if(is_leaf(v)) continue;
        int cnt = 0;
        for(int to : g[v]) {
            if(is_leaf(to)) {
                cnt++;
            }
        }
        if(cnt < 3) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
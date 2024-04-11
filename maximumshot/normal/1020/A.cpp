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

    int n, h, a, b, k;

    cin >> n >> h >> a >> b >> k;

    for(int i = 0;i < k;i++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if(ta == tb) {
            cout << abs(fa - fb) << "\n";
        }else {
            if(fa < a) {
                cout << a - fa + abs(a - fb) + abs(ta - tb) << "\n";
            }else if(fa > b) {
                cout << fa - b + abs(b - fb) + abs(ta - tb) << "\n";
            }else {
                cout << abs(fa - fb) + abs(ta - tb) << "\n";
            }
        }
    }

    return 0;
}
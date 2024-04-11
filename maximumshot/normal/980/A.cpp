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

    string s;

    cin >> s;

    int c0 = 0;
    int c1 = 0;

    for(char c : s) {
        if(c == 'o') {
            c0++;
        }else {
            c1++;
        }
    }

    if(c0 == 0 || c1 % c0 == 0) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}
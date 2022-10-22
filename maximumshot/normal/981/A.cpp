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

    int res = 0;

    for(int i = 0;i < (int)s.size();i++) {
        for(int j = i;j < (int)s.size();j++) {
            string t1 = s.substr(i, j - i + 1);
            string t2 = t1;
            reverse(ALL(t2));
            if(t1 != t2) {
                res = max(res, j - i + 1);
            }
        }
    }

    cout << res << "\n";

    return 0;
}
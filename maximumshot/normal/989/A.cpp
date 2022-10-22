#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
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

    for(int i = 0;i + 2 < (int)s.size();i++) {
        string t = s.substr(i, 3);
        sort(ALL(t));
        if(t == "ABC") {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
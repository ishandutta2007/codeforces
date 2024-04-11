
#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

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

bool is_substr(const string &sub, const string &big) {
    for(int i = 0;i + (int)sub.size() <= (int)big.size();i++) {
        if(big.substr(i, (int)sub.size()) == sub) {
            return true;
        }
    }
    return false;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    vec< string > a(n);

    for(auto &i : a) cin >> i;

    sort(ALL(a), [](const string &s1, const string &s2) {
        return s1.size() < s2.size();
    });

    for(int i = 0;i + 1 < (int)a.size();i++) {
        if(!is_substr(a[i], a[i + 1])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for(auto i : a) {
        cout << i << "\n";
    }

    return 0;
}
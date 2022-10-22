#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int h1, a1, c1;
    int h2, a2;

    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;

    vec< string > res;

    while(h2 > 0) {
        if(h1 > a2 || a1 >= h2) {
            res.push_back("STRIKE");
            h1 -= a2;
            h2 -= a1;
        }else {
            res.push_back("HEAL");
            h1 += c1 - a2;
        }
    }

    cout << (int)res.size() << "\n";

    for(string s : res) {
        cout << s << "\n";
    }

    return 0;
}
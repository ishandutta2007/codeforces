#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#else
#endif

    unordered_set< string > mp;

    int n;

    cin >> n;

    string s;

    for(int i = 0;i < n;i++) {
        cin >> s;
        if(mp.count(s)) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
            mp.insert(s);
        }
    }

    return 0;
}
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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    if((int)s.size() == 1) {
        cout << "-1\n";
        return 0;
    }

    if((int)s.size() == 2) {
        if(s == "25" || s == "50" || s == "75") {
            cout << "0\n";
            return 0;
        }
        swap(s[0], s[1]);
        if(s == "25" || s == "50" || s == "75") {
            cout << "1\n";
            return 0;
        }
        cout << "-1\n";
        return 0;
    }

    int res = inf;

    for(int x = 0;x < 100;x += 25) {
        for(int i = 0;i < (int)s.size();i++) {
            for(int j = 0;j < (int)s.size();j++) {
                if(i == j) continue;
                if(s[i] - '0' != x / 10 || s[j] - '0' != x % 10) continue;
                int tmp = (int)s.size() - 1 - i + (int)s.size() - 1 - j - 1;
                if(i > j) tmp++;
                string q;
                for(int k = 0;k < (int)s.size();k++) {
                    if(k == i || k == j) continue;
                    q.push_back(s[k]);
                }
                int fi = 0;
                while(fi < (int)q.size() && q[fi] == '0') fi++;
                if(fi == (int)q.size()) continue;
                tmp += fi;
                if(tmp < res) res = tmp;
            }
        }
    }

    cout << (res == inf ? -1 : res) << "\n";

    return 0;
}
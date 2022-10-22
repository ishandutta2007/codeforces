#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int type;
    cin >> type;

    string s;
    cin >> s;

    pair< int , string > res = {inf, ""};

    if(type == 12) {
        for(int h = 1;h <= 12;h++) {
            for(int m = 0;m < 60;m++) {
                string t = "";
                t.push_back(char(h / 10 + '0'));
                t.push_back(char(h % 10 + '0'));
                t.push_back(':');
                t.push_back(char(m / 10 + '0'));
                t.push_back(char(m % 10 + '0'));
                int dif = 0;
                for(int it = 0;it < 5;it++) dif += s[it] != t[it];
                if(dif < res.first) {
                    res.first = dif;
                    res.second = t;
                }
            }
        }
    }else {
        for(int h = 0;h < 24;h++) {
            for(int m = 0;m < 60;m++) {
                string t = "";
                t.push_back(char(h / 10 + '0'));
                t.push_back(char(h % 10 + '0'));
                t.push_back(':');
                t.push_back(char(m / 10 + '0'));
                t.push_back(char(m % 10 + '0'));
                int dif = 0;
                for(int it = 0;it < 5;it++) dif += s[it] != t[it];
                if(dif < res.first) {
                    res.first = dif;
                    res.second = t;
                }
            }
        }
    }

    cout << res.second << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}
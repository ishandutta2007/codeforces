#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 7e4 + 5;

char buff[100];

inline void getLine(string & s) {
    scanf("%s", buff);
    s = buff;
}

int n;
string s[N];
unordered_set< string > st[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        getLine(s[i]);
    }

    unordered_map< string, int > mp(n * 36);

    for(int i = 1;i <= n;i++) {
        string cur = "";
        for(int l = 0;l < 9;l++) {
            cur = "";
            for(int r = l;r < 9;r++) {
                cur.push_back(s[i][r]);
                st[i].insert(cur);
            }
        }
        for(string str : st[i]) {
            mp[str]++;
        }
    }

    for(int i = 1;i <= n;i++) {
        string res = "-1";
        for(string str : st[i]) {
            if(mp[str] == 1) {
                if(res == "-1" || res.size() > str.size()) {
                    res = str;
                }
            }
        }
        for(char c : res) {
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const L = 1e5 + 5;

char buffer[L];

inline void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

string good;
int mask_good;
set< char > GOOD;

inline bool isGood(char x) {
    return GOOD.count(x);
}

string t;
string s;
int pos;

bool solve() {
    if(pos == -1) {
        if((int)s.size() != (int)t.size()) {
            return 0;
        }
        for(int i = 0;i < (int)s.size();i++) {
            if(t[i] == '?') {
                if(!isGood(s[i])) {
                    return 0;
                }
            }else {
                if(s[i] != t[i]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    if((int)s.size() < (int)t.size() - 1) {
        return 0;
    }
    int cl = pos;
    int cr = (int)t.size() - pos - 1;
    for(int i = 0;cl > 0;cl--, i++) {
        if(t[i] == '?') {
            if(!isGood(s[i])) {
                return 0;
            }
        }else {
            if(s[i] != t[i]) {
                return 0;
            }
        }
    }
    for(int j = (int)t.size() - 1, i = (int)s.size() - 1;cr > 0;cr--, i--, j--) {
        if(t[j] == '?') {
            if(!isGood(s[i])) {
                return 0;
            }
        }else {
            if(s[i] != t[j]) {
                return 0;
            }
        }
    }
    cl = pos;
    cr = (int)t.size() - pos - 1;
    int L = cl;
    int R = (int)s.size() - cr - 1;
    for(int i = L;i <= R;i++) {
        if(isGood(s[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    readLine(good);

    mask_good = 0;

    for(char c : good) {
        GOOD.insert(c);
        mask_good |= (1 << (c - 'a'));
    }

    readLine(t);

    pos = -1;

    for(int i = 0;i < (int)t.size();i++) {
        if(t[i] == '*') {
            pos = i;
        }
    }

    int q;

    scanf("%d", &q);

    for(int iter = 0;iter < q;iter++) {
        readLine(s);
        puts(solve() ? "YES" : "NO");
    }

    return 0;
}
#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

string s,t;

bool can(int i, int j) {
    int pos = 0;
    for (int x = i; x <= j; ++x) {
        if (pos == t.size()) {
            return true;
        }
        if (s[x] != t[pos]) {
            return false;
        }
        ++pos;
    }
    for (int x = j - 1; x >= 0; --x) {
        if (pos == t.size()) {
            return true;
        }
        if (s[x] != t[pos]) {
            return false;
        }
        ++pos;
    }
    if (pos == t.size()) {
        return 1;
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        //cout << "QQQ " << endl;
        cin >> s >> t;
        bool ok = false;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (can(i, j)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
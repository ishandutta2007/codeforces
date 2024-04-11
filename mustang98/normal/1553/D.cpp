#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

string s, t;

bool check(int start) {
    int left = (int(s.size()) - start);
    if (left % 2 != t.size() % 2) {
        return 0;
    }
    int pos = 0;
    for (int i = start; i < s.size(); ++i) {
        if (pos == t.size()) {
            return true;
        }
        if (s[i] == t[pos]) {
            ++pos;
            continue;
        }
        ++i;
    }
    return pos == t.size();
}

bool check() {
    char fst = t[0];
    int p0 = -1, p1 = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != fst) {
            continue;
        }
        if (i % 2 == 0 && p0 == -1) {
            p0 = i;
        }
        if (i % 2 == 1 && p1 == -1) {
            p1 = i;
        }
    }
    if (check(p0) || check(p1)) {
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
        cin >> s >> t;
        if (check()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
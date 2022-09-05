#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}


struct atom {
    vector <char> pre, suf;
    ll ans;
};

atom merge(atom l, atom r) {
    atom ans; ans.ans = l.ans + r.ans;
    vector <char> tmp = l.suf;
    for (int i = 0; i < (int)r.pre.size(); i++) {
        tmp.push_back(r.pre[i]);
        if ((int)tmp.size() >= 4) {
            int now = (int)tmp.size() - 1;
            if (tmp[now - 3] == 'h' && tmp[now - 2] == 'a' && tmp[now - 1] == 'h' && tmp[now] == 'a') ++ans.ans;
        }
    }
    ans.pre = l.pre;
    int pos = 0;
    while ((int)ans.pre.size() < 3 && pos < (int)r.pre.size()) {
        ans.pre.push_back(r.pre[pos]);
        ++pos;
    }
    ans.suf = r.suf;
    pos = (int)l.suf.size() - 1;
    while ((int)ans.suf.size() < 3 && pos >= 0) {
        ans.suf.push_back(0);
        for (int i = (int)ans.suf.size() - 1; i >= 1; i--) ans.suf[i] = ans.suf[i - 1];
        ans.suf[0] = l.suf[pos];
        --pos;
    }
    return ans;
}

map <string, atom> mp;
int T, n, len;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        mp.clear();
        cin >> n;
        string las;
        for (int i = 1; i <= n; i++) {
            string id, foo;
            cin >> id >> foo;
            if ((int)foo.size() == 2) {
                string c; cin >> c; int len = c.length();
                atom now; now.ans = 0;
                for (int i = 3; i < len; i++) {
                    if (c[i - 3] == 'h' && c[i - 2] == 'a' && c[i - 1] == 'h' && c[i] == 'a') {
                        ++now.ans;
                    }
                }
                for (int i = 0; i <= min(len - 1, 2); i++) now.pre.push_back(c[i]);
                for (int i = max(len - 3, 0); i <= len - 1; i++) now.suf.push_back(c[i]);
                mp[id] = now;
            } else {
                string a, b;
                cin >> a >> foo >> b;
                mp[id] = merge(mp[a], mp[b]);
            }
            las = id;
        }
        print(mp[las].ans, '\n');
    }
    return 0;
}
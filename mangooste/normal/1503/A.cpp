#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

inline bool good(const string &s) {
    int bal = 0;
    for (auto c : s) {
        bal += (c == '(' ? 1 : -1);
        if (bal < 0) {
            return false;
        }
    }
    return bal == 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int cnt = count(all(s), '1');
        string a, b;
        int who = 0;
        int open = 0;
        for (auto c : s) {
            if (c == '0') {
                if (who) {
                    a.push_back('(');
                    b.push_back(')');
                } else {
                    b.push_back('(');
                    a.push_back(')');
                }
                who ^= 1;
            } else {
                if (open < cnt / 2) {
                    a.push_back('(');
                    b.push_back('(');
                } else {
                    a.push_back(')');
                    b.push_back(')');
                }
                open++;
            }
        }
        if (good(a) && good(b)) {
            cout << "YES\n" << a << '\n' << b << '\n';
        } else {
            cout << "NO\n";
        }
    }    
}
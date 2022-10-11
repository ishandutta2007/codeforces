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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = len(s);
        vec<char> need(26);
        for (auto x : s) {
            need[x - 'a'] = 1;
        }
        int diff = accumulate(all(need), 0);
        int st = 0;
        while (diff--) {
            for (char cur = 'z'; cur >= 'a'; cur--) {
                if (need[cur - 'a']) {
                    int first = st;
                    while (s[first] != cur) {
                        first++;
                    }
                    vec<char> suf(26);
                    for (int i = first + 1; i < n; i++) {
                        suf[s[i] - 'a'] = 1;
                    }
                    bool ok = true;
                    for (int i = 0; i < 26 && ok; i++) {
                        if (i != cur - 'a' && need[i]) {
                            ok &= suf[i];
                        }
                    }
                    if (ok) {
                        cout << cur;
                        need[cur - 'a'] = 0;
                        st = first + 1;
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }    
}
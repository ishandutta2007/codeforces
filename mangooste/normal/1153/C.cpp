#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

    int n;
    string s;
    cin >> n >> s;

    int dont_know = 0;
    int total = 0;
    for (auto c : s)
        if (c == '?')
            dont_know++;
        else
            total += c == '(' ? 1 : -1;

    if (total + dont_know < 0 || total - dont_know > 0 || ((total + dont_know) & 1) != 0) {
        cout << ":(\n";
        return 0;
    }

    int close = (total + dont_know) >> 1;
    int open = dont_know - close;

    int balance = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            s[i] = (open-- > 0 ? '(' : ')');

        balance += s[i] == '(' ? 1 : -1;
        if (balance < 0 || (i != n - 1 && balance == 0)) {
            cout << ":(\n";
            return 0;
        }
    }

    cout << (balance == 0 ? s : ":(") << '\n';
}
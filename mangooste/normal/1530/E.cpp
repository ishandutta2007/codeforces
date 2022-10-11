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

const int ALPHA = 26;

void solve() {
    string s;
    cin >> s;
    int n = len(s);

    vector<int> count(ALPHA);
    for (auto c : s)
        count[c - 'a']++;

    for (int i = 0; i < ALPHA; i++)
        if (count[i] == 1) {
            cout << char('a' + i);
            for (int j = 0; j < ALPHA; j++)
                if (j != i)
                    cout << string(count[j], 'a' + j);

            cout << '\n';
            return;
        }

    int first = 0;
    while  (count[first] == 0)
        first++;

    if (count[first] - 2 <= n - count[first]) {
        cout << string(2, 'a' + first);
        int left = count[first] - 2;
        for (int i = first + 1; i < ALPHA; i++)
            for (int j = 0; j < count[i]; j++) {
                cout << char('a' + i);
                if (left) {
                    left--;
                    cout << char('a' + first);
                }
            }

        cout << '\n';
        return;
    }

    cout << char('a' + first);
    vector<char> free;
    for (int i = first + 1; i < ALPHA; i++)
        if (count[i])
            free.push_back(i);

    if (free.empty()) {
        cout << string(count[first] - 1, 'a' + first) << '\n';
        return;
    }

    if (len(free) == 1) {
        cout << string(count[free[0]], 'a' + free[0]);
        cout << string(count[first] - 1, 'a' + first) << '\n';
        return;
    }

    cout << char('a' + free[0]);
    count[free[0]]--;
    cout << string(count[first] - 1, 'a' + first);
    cout << char('a' + free[1]);
    count[free[1]]--;

    for (auto i : free)
        cout << string(count[i], 'a' + i);

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
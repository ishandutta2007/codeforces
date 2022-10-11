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
    cin >> n >> ws;
    vector<string> a(n);
    for (auto &s : a)
        getline(cin, s);

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1])
            continue;

        int j = 0;
        while (j < len(a[i]) && j < len(a[i + 1]) && a[i][j] == a[i + 1][j])
            j++;

        a[i].resize(j);
        assert(a[i] <= a[i + 1]);
    }

    for (const auto &s : a)
        cout << s << '\n';
}
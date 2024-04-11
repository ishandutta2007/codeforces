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

vector<int> zFunction(string s) {
    int n = int(s.size());
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto get = [&](string ss) {
        string res = ss;
        while (len(res) < k)
            res += ss;
 
        while (len(res) > k)
            res.pop_back();
 
        return res;
    };

    auto z = zFunction(s);
    z[0] = n;

    int best = 0;
    while (true) {
        int pos = best + 1;
        while (pos < n && pos + z[pos] >= min(pos + best + 1, n))
            pos = min(n, pos + best + 1);

        if (pos == n)
            break;

        int where = pos + z[pos];
        assert(where != n);
        assert(where > 0);
        if (s[where] < s[z[pos]])
            best = where;
        else
            break;
    }

    cout << get(s.substr(0, best + 1)) << '\n';
}
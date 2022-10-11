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

    const int LOG = 31;
    vector<ll> sum(LOG);
    vector<multiset<int>> sets(LOG);

    int q;
    cin >> q;

    int size = 0;
    while (q--) {
        char type;
        int x;
        cin >> type >> x;
        size += type == '+' ? 1 : -1;

        int block = 0;
        while ((1 << block) <= x)
            block++;

        sum[block] += type == '+' ? x : -x;
        if (type == '+')
            sets[block].insert(x);
        else
            sets[block].erase(sets[block].find(x));

        int answer = size;
        ll pref = 0;
        for (int i = 0; i < LOG; i++) {
            if (len(sets[i]) && *sets[i].begin() > 2 * pref)
                answer--;

            pref += sum[i];
        }

        cout << answer << '\n';
    }
}
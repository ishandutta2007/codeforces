#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

struct event {
    int x, type, id;

    bool operator<(const event &e) const {
        if (x != e.x)
            return x < e.x;

        return type < e.type;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    vec<int> b(n);
    for (auto &x : b)
        cin >> x;

    vec<event> events;
    ll answer = 0;

    for (int i = 0; i < n; i++) {
        answer += abs(a[i] - b[i]);
        if (a[i] == b[i])
            continue;

        events.push_back({ min(a[i], b[i]), 0, i });
        events.push_back({ max(a[i], b[i]), 1, i });
    }

    sort(all(events));
    ar<set<pair<int, int>>, 2> st;

    int max_sub = 0;
    for (const auto &[x, type, id] : events) {
        int who = a[id] < b[id];

        if (type == 1) {
            auto it = st[who ^ 1].upper_bound({ a[id] ^ b[id] ^ x, n });
            if (it != st[who ^ 1].end())
                max_sub = max(max_sub, x - it->first);

            if (it != st[who ^ 1].begin())
                max_sub = max(max_sub, x - (a[id] ^ b[id] ^ x));

            st[who].erase({ a[id] ^ b[id] ^ x, id });
        } else {
            st[who].insert({ x, id });
        }
    }

    answer -= 2 * max_sub;
    cout << answer << '\n';
}
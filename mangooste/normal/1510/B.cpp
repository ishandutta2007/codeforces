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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int d, n;
    cin >> d >> n;

    vec<int> masks(n);
    for (auto &mask : masks) {
        string s;
        cin >> s;

        reverse(all(s));
        for (int i = 0; i < d; i++)
            mask = mask * 2 + s[i] - '0';
    }
    sort(all(masks), [&](int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    });

    vec<vec<int>> g(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if ((masks[i] & masks[j]) == masks[i])
                g[i].push_back(j);

    vec<int> matched(n, -1);
    vec<int> used(n);
    int timer = 1;

    auto khun = y_combinator([&](auto khun, int v) -> bool {
        if (used[v] == timer)
            return false;

        used[v] = timer;

        for (auto u : g[v])
            if (matched[u] == -1) {
                matched[u] = v;
                return true;
            }

        for (auto u : g[v])
            if (khun(matched[u])) {
                matched[u] = v;
                return true;
            }

        return false;
    });

    for (int i = 0; i < n; i++) {
        khun(i);
        timer++;
    }

    vec<int> nxt(n, -1);
    for (int i = 0; i < n; i++)
        if (matched[i] != -1)
            nxt[matched[i]] = i;

    vec<int> answer;

    auto add = [&](int mask) {
        for (int i = 0; i < d; i++)
            if ((mask >> i) & 1)
                answer.push_back(i);
    };

    for (int i = 0; i < n; i++)
        if (matched[i] == -1) {
            if (len(answer))
                answer.push_back(-1);

            int prev = 0;
            for (int j = i; j != -1; j = nxt[j]) {
                add(masks[j] ^ prev);
                prev = masks[j];
            }
        }

    cout << len(answer) << '\n';
    for (auto x : answer)
        if (x == -1)
            cout << "R ";
        else
            cout << x << ' ';

    cout << '\n';
}
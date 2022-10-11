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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<ar<int, 3>, bool> mem;

inline bool ask(int a, int b, int c) {
    if (mem.find({a, b, c}) != mem.end())
        return mem[{a, b, c}];
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    string res;
    cin >> res;
    return mem[{a, b, c}] = mem[{c, b, a}] = res == "Yes";
}

inline void answer(int x) {
    cout << "! " << x + 1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int dep = 0, already = 1, cur = 1;
    while (already != n) {
        cur *= k;
        already += cur;
        dep++;
    }

    vec<int> ord(n);
    iota(all(ord), 0);
    shuffle(all(ord), rng);

    int leaf = -1;
    for (auto cur : ord) {
        int x;
        do {
            x = rng() % n;
        } while (x == cur);

        bool ok = true;
        for (auto i : ord)
            if (i != cur && i != x && ask(i, cur, x)) {
                ok = false;
                break;
            }

        if (!ok)
            continue;
        if (leaf == -1) {
            leaf = cur;
            continue;
        }

        vec<int> on_way;
        on_way.reserve(2 * dep - 1);
        for (int i = 0; i < n; i++)
            if (i != leaf && i != cur && ask(leaf, i, cur))
                on_way.push_back(i);

        if (len(on_way) != 2 * dep - 1)
            continue;

        sort(all(on_way), [&](int a, int b) {
            return ask(leaf, a, b);
        });
        answer(on_way[dep - 1]);
    }
    assert(false);
}
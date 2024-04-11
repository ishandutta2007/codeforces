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

template<typename T>
vector<T> substr(const vector<T> &a, int l, int r) {
    vector<T> result(r - l);
    for (int i = l; i < r; i++)
        result[i - l] = a[i];

    return result;
}

int mex(const vector<int> &a) {
    static vector<char> used;
    used.assign(len(a) + 1, 0);
    for (auto x : a)
        if (x < len(used))
            used[x] = 1;

    for (int i = 0;; i++)
        if (!used[i])
            return i;
}

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    map<vector<array<int, 3>>, int> was;
    vector<array<int, 3>> grundy;
    grundy.push_back({0, 0, 0});

    int st = -1, fn = -1;
    for (int i = 1; ; i++) {
        grundy.push_back({0, 0, 0});
        grundy[i][0] = mex({grundy[max(0, i - x)][0], grundy[max(0, i - y)][1], grundy[max(0, i - z)][2]});
        grundy[i][1] = mex({grundy[max(0, i - x)][0], grundy[max(0, i - z)][2]});
        grundy[i][2] = mex({grundy[max(0, i - x)][0], grundy[max(0, i - y)][1]});

        if (i < max({x, y, z}))
            continue;

        auto current = substr(grundy, i - max({x, y, z}), i);
        auto it = was.find(current);
        if (it == was.end())
            was[current] = i;
        else {
            st = it->second;
            fn = i;
            break;
        }
    }

    auto get_grundy = [&](ll value, int type) {
        value = max(0ll, value);
        if (value < st)
            return grundy[value][type];

        value -= st;
        value %= (fn - st);
        return grundy[st + value][type];
    };

    int total = 0;
    vector<ll> a(n);
    vector<int> gr(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        gr[i] = get_grundy(a[i], 0);
        total ^= gr[i];
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        total ^= gr[i];
        answer += total == get_grundy(a[i] - x, 0);
        answer += total == get_grundy(a[i] - y, 1);
        answer += total == get_grundy(a[i] - z, 2);
        total ^= gr[i];
    }
    cout << answer << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
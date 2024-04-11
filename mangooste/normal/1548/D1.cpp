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
    cin >> n;
    array<int, 16> points{};
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x >>= 1, y >>= 1;
        points[((x & 3) << 2) ^ (y & 3)]++;
    }

    auto get = [&](int mask, int pos) {
        return (mask >> (pos << 1)) & 3;
    };

    ll answer = 0;
    for (int first = 0; first < 16; first++)
        for (int second = first; second < 16; second++)
            for (int third = second; third < 16; third++) {
                ll pairs = 1ll * points[first] * points[second] * points[third];
                if (first == second && second == third)
                    pairs = 1ll * points[first] * (points[first] - 1) * (points[first] - 2) / 6;
                else if (first == second)
                    pairs = 1ll * points[first] * (points[first] - 1) / 2 * points[third];
                else if (second == third)
                    pairs = 1ll * points[second] * (points[second] - 1) / 2 * points[first];

                int parity = 1;
                for (auto [a, b] : {pair<int, int>{first, second}, {second, third}, {third, first}})
                    parity ^= (((get(a, 0) + get(b, 0)) & 1) != 0 || ((get(a, 1) + get(b, 1)) & 1) != 0);

                if (parity == 1)
                    answer += pairs;
            }

    cout << answer << '\n';
}
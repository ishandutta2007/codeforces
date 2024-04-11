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

const ld EPS = 1e-7;

ld solve(ld a, ld b, ld c, ld v, int steps) {
    if (a < EPS && b < EPS)
        return steps;

    if (a < EPS || b < EPS) {
        b = max(a, b);
        ld answer = 0;
        ld coeff = 1;
        while (b > EPS) {
            answer += steps * c * coeff;
            coeff *= b;
            b -= v;
            c += v;
            steps++;
        }
        answer += steps * coeff;
        return answer;
    }

    ld answer = steps * ld(c);
    {
        ld cnt = min(a, v);
        answer += solve(a - cnt, b + cnt / 2, c + cnt / 2, v, steps + 1) * a;
    }

    {
        ld cnt = min(b, v);
        answer += solve(a + cnt / 2, b - cnt, c + cnt / 2, v, steps + 1) * b;
    }

    return answer;
}

void solve() {
    ld a, b, c, v;
    cin >> a >> b >> c >> v;
    cout << solve(a, b, c, v, 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
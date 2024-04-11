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

void solve() {
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    array<int, 7> cnt;
    for (auto &x : cnt)
        cin >> x;

    array<int, 7> answer{};
    for (answer[1] = 0; answer[1] <= cnt[1]; answer[1]++)
        for (answer[2] = 0; answer[2] <= cnt[2]; answer[2]++)
            for (answer[4] = 0; answer[4] <= cnt[4]; answer[4]++) {
                a1 -= answer[1], b1 -= answer[1], a2 -= cnt[1] - answer[1], b2 -= cnt[1] - answer[1];
                a1 -= answer[2], c1 -= answer[2], a2 -= cnt[2] - answer[2], c2 -= cnt[2] - answer[2];
                b1 -= answer[4], c1 -= answer[4], b2 -= cnt[4] - answer[4], c2 -= cnt[4] - answer[4];

                int to_sub = min(cnt[0], min({a1, b1, c1}));
                a1 -= to_sub, b1 -= to_sub, c1 -= to_sub;
                answer[0] += to_sub;
                a2 -= cnt[0] - to_sub, b2 -= cnt[0] - to_sub, c2 -= cnt[0] - to_sub;

                if (min({a1, b1, c1, a2, b2, c2}) >= 0) {
                    int add = min(a1, cnt[3]);
                    answer[3] += add;

                    if (cnt[3] - add <= a2) {
                        int add = min(b1, cnt[5]);
                        answer[5] += add;

                        if (cnt[5] - add <= b2) {
                            int add = min(c1, cnt[6]);
                            answer[6] += add;

                            if (cnt[6] - add <= c2) {
                                for (int i = 0; i < 7; i++)
                                    cout << answer[i] << " \n"[i == 6];

                                return;
                            }
                            answer[6] -= add;
                        }
                        answer[5] -= add;
                    }
                    answer[3] -= add;
                }

                a1 += to_sub, b1 += to_sub, c1 += to_sub;
                answer[0] -= to_sub;
                a2 += cnt[0] - to_sub, b2 += cnt[0] - to_sub, c2 += cnt[0] - to_sub;

                a1 += answer[1], b1 += answer[1], a2 += cnt[1] - answer[1], b2 += cnt[1] - answer[1];
                a1 += answer[2], c1 += answer[2], a2 += cnt[2] - answer[2], c2 += cnt[2] - answer[2];
                b1 += answer[4], c1 += answer[4], b2 += cnt[4] - answer[4], c2 += cnt[4] - answer[4];
            }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
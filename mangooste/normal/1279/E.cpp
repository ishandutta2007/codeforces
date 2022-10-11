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

constexpr ll INF = 2e18;
constexpr int N = 55;

ll fact[N], dp[N];

ll add(ll a, ll b) {
    return min(a + b, INF);
}

ll mult(ll a, ll b) {
    return __int128(a) * b >= INF ? INF : a * b;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mult(fact[i - 1], i);

    dp[0] = 1;
    for (int n = 1; n < N; n++)
        for (int st = 1; st <= n; st++)
            dp[n] = add(dp[n], mult(fact[max(0, st - 2)], dp[n - st]));
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    if (dp[n] < k) {
        cout << "-1\n";
        return;
    }

    vector<int> perm(n);
    vector<int> parent(n + 1);

    for (int i = 0; i < n;)
        for (int st = 1;; st++) {
            const ll current = mult(fact[max(0, st - 2)], dp[n - i - st]);
            if (current >= k) {
                vector<char> used(st);
                perm[i] = i + st;

                parent[1] = st;
                parent[st] = 1;
                for (int i = 2; i < st; i++)
                    parent[i] = i;

                for (int j = i + 1, ways = st - 1; j < i + st - 1; j++, ways--)
                    for (int pos = 1; pos < st; pos++) {
                        const int me = j - i + 1;
                        if (!used[pos] && parent[me] != pos) {
                            const ll current = mult(fact[ways - 2], dp[n - i - st]);
                            if (current >= k) {
                                used[pos] = 1;
                                perm[j] = i + pos;

                                int a = parent[pos];
                                int b = parent[me];
                                parent[a] = b;
                                parent[b] = a;
                                break;
                            }

                            k -= current;
                        }
                    }

                if (st != 1) {
                    perm[i + st - 1] = 1;
                    while (used[perm[i + st - 1]])
                        perm[i + st - 1]++;

                    perm[i + st - 1] += i;
                }

                i += st;
                break;
            }

            k -= current;
        }

    for (int i = 0; i < n; i++)
        cout << perm[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    init();

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
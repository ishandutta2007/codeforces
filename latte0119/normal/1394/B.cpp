#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

bool ban[100][100];

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vpint> G(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].eb(c, b);
    }

    vector<vint> lis(N);
    rep(i, N) {
        sort(all(G[i]));
        rep(j, G[i].size()) {
            lis[G[i][j].se].eb((G[i].size() - 1) * K + j);
        }
    }

    rep(i, N) {
        sort(all(lis[i]));
        for (int j = 0; j + 1 < lis[i].size(); j++)
            if (lis[i][j] == lis[i][j + 1]) {
                ban[lis[i][j]][lis[i][j]] = true;
            }
        for (auto x : lis[i]) {
            for (auto y : lis[i]) {
                if (y / K < x / K) {
                    ban[y][x] = true;
                } else {
                    break;
                }
            }
        }
    }

    vector<int> P(K);
    iota(all(P), 0);
    int ans = 0;
    do {
        vector<int> C(K, 0);
        rep(i, K) {
            rep(j, i) {
                if (P[j] < P[i]) C[i]++;
            }
        }
        bool ok = true;
        rep(i, K) rep(j, i + 1) if (ban[j * K + C[j]][i * K + C[i]]) ok = false;
        if (ok) ans++;
        // if (ok) {
        //     cout << C << endl;
        //     rep(i, N) {
        //         cout << i << " " << G[i][C[G[i].size() - 1]].se << endl;
        //     }
        // }
    } while (next_permutation(all(P)));
    cout << ans << endl;
    return 0;
}
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

int N, D, M;

signed main() {
    scanf("%lld%lld%lld", &N, &D, &M);
    vector<int> S, L;
    rep(i, N) {
        int a;
        scanf("%lld", &a);
        if (a <= M)
            S.pb(a);
        else
            L.pb(a);
    }
    sort(all(S));
    sort(all(L));
    reverse(all(S));
    reverse(all(L));
    vector<int> accS(S.size() + 1), accL(L.size() + 1);
    rep(i, S.size()) accS[i + 1] = accS[i] + S[i];
    rep(i, L.size()) accL[i + 1] = accL[i] + L[i];

    int ans = accumulate(all(S), 0ll);
    for (int i = 1; i <= L.size(); i++) {
        if (S.size() + (L.size() - i) < (i - 1) * D) break;
        int tmp = max(0ll, (i - 1) * D - ((int)L.size() - i));

        chmax(ans, accL[i] + accS[S.size() - tmp]);
    }
    cout << ans << endl;
    return 0;
}
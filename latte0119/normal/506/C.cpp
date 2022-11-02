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

int N, M, K, P;
int H[111111], A[111111];

signed main() {
    scanf("%lld%lld%lld%lld", &N, &M, &K, &P);
    rep(i, N) scanf("%lld%lld", &H[i], &A[i]);

    // vint ord(N);
    // iota(all(ord), 0);
    // sort(all(ord), [&](int i, int j) { H[i] + A[i] * M < H[j] + A[j] * M; });
    // reverse(all(ord));

    int lb = *max_element(A, A + N) - 1,
        ub = 10'000'000'000'000ll;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        vector<int> num(M);
        int tot = 0;
        rep(i, N) {
            if (H[i] + A[i] * M <= mid) continue;
            int x = mid;
            int j = M;
            while (j) {
                int tmp = min(x / A[i], j);
                x -= tmp * A[i];
                j -= tmp;

                int tar;
                if (j == 0)
                    tar = H[i];
                else
                    tar = A[i];

                tmp = (max(tar - x, 0ll) + P - 1) / P;
                tot += tmp;
                num[j] += tmp;
                x += tmp * P;
            }
            if (tot > M * K) break;
        }
        rep(i, M - 1) {
            int tmp = max(num[i] - K, 0ll);
            num[i] -= tmp;
            num[i + 1] += tmp;
        }
        if (num[M - 1] > K || tot > M * K)
            lb = mid;
        else
            ub = mid;
    }
    cout << ub << endl;
    return 0;
}
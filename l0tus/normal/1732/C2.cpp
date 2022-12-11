#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cout << "[Debug] " << x << '\n'
#else
#define debug(x)
#endif

using str = string;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define mp make_pair
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define lb lower_bound
#define ub upper_bound

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define vl first
#define vr second

const ll INF = 1e9;
const int MOD = (int)1e9 + 7; // 998244353;
const int MN = (int)2e5 + 5;

ll A[MN], B[MN], AtoB[MN], BtoA[MN], X[MN], S[MN];

ll f(int l, int r)
{
    return (S[r] - S[l - 1]) - (X[r] ^ X[l - 1]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    FAST_IO;
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        int idx = 1;
        FOR(i, 1, N + 1)
        {
            cin >> A[i];
            if (A[i])
            {
                B[idx] = A[i];
                BtoA[idx] = i;
                idx++;
            }
        }
        X[0] = S[0] = 0;
        FOR(i, 1, N + 1)
        {
            X[i] = X[i - 1] ^ A[i];
            S[i] = S[i - 1] + A[i];
        }
        while (Q--)
        {
            int LL, RR;
            cin >> LL >> RR;
            int L = lower_bound(BtoA + 1, BtoA + idx, LL) - BtoA;
            int R = upper_bound(BtoA + 1, BtoA + idx, RR) - 1 - BtoA;
            pi ans = {LL, LL};
            int len = INF;
            for (int i = L; i <= min(L + 40, R); i++)
            {
                for (int j = R; j >= max(R - 40, L); j--)
                {
                    if (i > j)
                        continue;
                    if (f(LL, RR) == f(BtoA[i], BtoA[j]) && BtoA[j] - BtoA[i] + 1 < len)
                    {
                        ans = {BtoA[i], BtoA[j]};
                        len = BtoA[j] - BtoA[i] + 1;
                    }
                }
            }
            cout << ans.vl << ' ' << ans.vr << '\n';
        }
    }
}
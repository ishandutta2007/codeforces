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
#define f first
#define s second
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

const ll INF = 1e18;
const int MOD = (int)1e9 + 7; // 998244353;
const int MN = (int)2e5 + 5;

vi A(MN), X(MN);
vl S(MN);
vi table;
vi same_odd[MN], same_even[MN];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    FAST_IO;
    int N, Q;
    cin >> N >> Q;
    FOR(i, 1, N + 1)
    {
        cin >> A[i];
        X[i] = X[i - 1] ^ A[i];
        table.pb(X[i]);
        S[i] = S[i - 1] + A[i];
    }
    sor(table);
    table.erase(unique(all(table)), table.end());
    F0R(i, N + 1)
    {
        int num = lb(all(table), X[i]) - table.bg();
        if (i % 2)
            same_odd[num].pb(i);
        else
            same_even[num].pb(i);
    }
    F0R(i, Q)
    {
        int L, R;
        cin >> L >> R;
        int ans;
        if (X[R] ^ X[L - 1])
            ans = -1;
        else if (S[R] - S[L - 1] == 0)
        {
            ans = 0;
        }
        else
        {

            int a = lb(all(table), X[i]) - table.bg();
            if ((R - L + 1) % 2)
            {
                ans = 1;
            }
            else
            {
                if (A[L] == 0 || A[R] == 0)
                    ans = 1;
                else
                {
                    ans = -1;
                    {
                        int num = lb(all(table), X[L - 1]) - table.bg();
                        auto &v = ((L - 1) % 2) ? same_even[num] : same_odd[num];
                        int idx = ub(all(v), L - 1) - v.bg();
                        if (idx < sz(v) && v[idx] <= R)
                            ans = 2;
                    }
                    {
                        int num = lb(all(table), X[R]) - table.bg();
                        auto &v = (R % 2) ? same_even[num] : same_odd[num];
                        int idx = lb(all(v), R) - v.bg() - 1;
                        if (idx >= 0 && v[idx] >= L - 1)
                            ans = 2;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
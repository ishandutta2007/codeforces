#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 1130013, MX = 1000013;
const ll LLINF = 2696969696969696969ll;

int N, M, K;
pll A[MAXN];
ll cost[MAXN];
vpl gain[MAXN];
ll seg[2 * MAXN], lazy[2 * MAXN];
ll ans = -LLINF;

void build(int w, int L, int R)
{
    lazy[w] = 0;
    if (L == R)
    {
        seg[w] = (cost[L] == 0 ? -LLINF : -cost[L]);
        return;
    }
    int mid = (L + R) >> 1;
    build(w << 1, L, mid);
    build(w << 1 | 1, mid + 1, R);
    seg[w] = max(seg[w << 1], seg[w << 1 | 1]);
}
void push(int w, int L, int R)
{
    if (lazy[w] == 0) return;
    seg[w] += lazy[w];
    if (L != R)
    {
        lazy[w << 1] += lazy[w];
        lazy[w << 1 | 1] += lazy[w];
    }
    lazy[w] = 0;
    return;
}
void update(int w, int L, int R, int a, int b, ll v)
{
    push(w, L, R);
    if (b < L || R < a) return;
    if (a <= L && R <= b)
    {
        lazy[w] += v;
        push(w, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(w << 1, L, mid, a, b, v);
    update(w << 1 | 1, mid + 1, R, a, b, v);
    seg[w] = max(seg[w << 1], seg[w << 1 | 1]);
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> K;
    FOR(i, 0, N)
    {
        cin >> A[i].fi >> A[i].se;
    }
    sort(A, A + N);
    FOR(i, 0, M)
    {
        ll a, b;
        cin >> a >> b;
        if (cost[a] == 0 || cost[a] > b)
        {
            cost[a] = b;
        }
    }
    FOR(i, 0, K)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        gain[x + 1].PB({y + 1, z});
    }
    build(1, 0, MX);
    int iter = 0;
    FOR(i, 0, N)
    {
        while(iter < A[i].fi)
        {
            iter++;
            // cerr << "iter " << iter << endl;
            for (auto a : gain[iter])
            {
                update(1, 0, MX, a.fi, MX, a.se);
                // cerr << "increase " << a.fi << ' ' << MX << " by " << a.se << endl;
                //increase a.fi..mx-1 by a.se
            }
        }
        ckmax(ans, -A[i].se + seg[1]);
        //ckmax(ans, max value in segtree - A[i].se)
    }
    cout << ans << '\n';
    return 0;
}
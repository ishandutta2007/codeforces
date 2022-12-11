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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
pair<pii, pii> arr[MAXN];
bool ans;
vi compress;
int seg[12 * MAXN], lazy[12 * MAXN];

void push(int w, int L, int R)
{
    if (lazy[w] == SZ(compress)) return;
    ckmin(seg[w], lazy[w]);
    if (L != R)
    {
        ckmin(lazy[w << 1], lazy[w]);
        ckmin(lazy[w << 1 | 1], lazy[w]);
    }
    lazy[w] = SZ(compress);
    return;
}
void update(int w, int L, int R, int a, int b, int v)
{
    push(w, L, R);
    if (b < L || R < a) return;
    if (a <= L && R <= b)
    {
        ckmin(lazy[w], v);
        push(w, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(w << 1, L, mid, a, b, v);
    update(w << 1 | 1, mid + 1, R, a, b, v);
    seg[w] = min(seg[w << 1], seg[w << 1 | 1]);
}
int query(int w, int L, int R, int a, int b)
{
    push(w, L, R);
    if (a <= L && R <= b)
    {
        return seg[w];
    }
    int mid = (L + R) >> 1;
    if (b <= mid) return query(w << 1, L, mid, a, b);
    if (mid < a) return query(w << 1 | 1, mid + 1, R, a, b);
    return min(query(w << 1, L, mid, a, b), query(w << 1 | 1, mid + 1, R, a, b));
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> arr[i].fi.fi >> arr[i].fi.se >> arr[i].se.fi >> arr[i].se.se;
        arr[i].fi.se++; arr[i].se.se++;
        compress.PB(arr[i].fi.fi);
        compress.PB(arr[i].fi.se);
        compress.PB(arr[i].se.fi);
        compress.PB(arr[i].se.se);
    }
    sort(ALL(compress)); compress.erase(unique(ALL(compress)), compress.end());
    FOR(i, 0, N)
    {
        arr[i].fi.fi = LB(ALL(compress), arr[i].fi.fi) - compress.begin();
        arr[i].fi.se = LB(ALL(compress), arr[i].fi.se) - compress.begin();
        arr[i].se.fi = LB(ALL(compress), arr[i].se.fi) - compress.begin();
        arr[i].se.se = LB(ALL(compress), arr[i].se.se) - compress.begin();
    }
    FOR(i, 0, 12 * MAXN)
    {
        lazy[i] = SZ(compress); seg[i] = SZ(compress);
    }
    sort(arr, arr + N);
    FOR(i, 0, N)
    {
        if (query(1, 0, SZ(compress) - 1, arr[i].se.fi, arr[i].se.se - 1) <= arr[i].fi.fi)
        {
            cout << "NO\n";
            return 0;
        }
        update(1, 0, SZ(compress) - 1, arr[i].se.fi, arr[i].se.se - 1, arr[i].fi.se);
        //everything in this range must start at at least this.
    }
    // cerr << "HI\n";
    // cerr << "YEAH\n";
    FOR(i, 0, N)
    {
        swap(arr[i].fi.fi, arr[i].se.fi);
        swap(arr[i].fi.se, arr[i].se.se);
    }
    FOR(i, 0, 12 * MAXN)
    {
        lazy[i] = SZ(compress); seg[i] = SZ(compress);
    }
    sort(arr, arr + N);
    FOR(i, 0, N)
    {
        // cerr << arr[i].fi.fi << ' ' << arr[i].fi.se << ' ' << arr[i].se.fi << ' ' << arr[i].se.se << endl;
        if (query(1, 0, SZ(compress) - 1, arr[i].se.fi, arr[i].se.se - 1) <= arr[i].fi.fi)
        {
            cout << "NO\n";
            return 0;
        }
        update(1, 0, SZ(compress) - 1, arr[i].se.fi, arr[i].se.se - 1, arr[i].fi.se);
        //everything in this range must start at at least this.
    }
    cout << "YES\n";
    return 0;
    //meh i think we can check pairs?
    //is there any i < j such that:
    //arr[i].fi.se <= arr[j].se.fi
    //min(arr[i].se.fi, arr[j].se.fi) < max(arr[i].se.se, arr[j].se.se)
}
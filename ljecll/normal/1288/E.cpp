#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define MAXN 300013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
int arr[MAXN];
pii ans[MAXN];
bitset<MAXN> vis;
int val[MAXN];
ordered_set<int> vals;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    FOR(i, 0, M)
    {
        cin >> arr[i]; arr[i]--;
        vis[arr[i]] = true;
    }
    FOR(i, 0, N)
    {
        ans[i].fi = (vis[i] ? 0 : i);
        ans[i].se = i;
        val[i] = i;
        vals.insert(i);
    }
    FOR(i, 0, M)
    {
        int idx = arr[i];
        ckmax(ans[idx].se, vals.order_of_key(val[idx]));
        vals.erase(val[idx]);
        val[idx] = -i - 1;
        vals.insert(val[idx]);
    }
    FOR(i, 0, N)
    {
        ckmax(ans[i].se, vals.order_of_key(val[i]));
    }
    //now the latest he's ever been. it'll be just before adj locations.
    //insert a value, remove a value, query the index of a value?
    FOR(i, 0, N)
    {
        cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << '\n';
    }
    return 0;
    //well the earliest he's been: if he's ever been seen at all, it's 0. otherwise, it's i.
}
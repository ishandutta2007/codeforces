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
 
mt19937 rng(42);
 
template<class T>
T randomize(T mod)
{
	return uniform_int_distribution<T>(0, mod - 1)(rng);
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
 
const int MAXN = 1000013;
 
int N;
ll arr[MAXN];
int sp[MAXN];
vi primes;
ll ans;
 
ll test(int p)
{
    ll res = 0;
    FOR(i, 0, N)
    {
        if (arr[i] <= p)
        {
            res += (p - arr[i]);
            continue;
        }
        int v = (arr[i] % p);
        res += min(v, p - v);
        // if (p == 3) cerr << min(v, p - v) << endl;
    }
    // cerr << p << ' ' << res << endl;
    return res;
}
vi getfactors(ll x)
{
    vi res;
    for (ll p : primes)
    {
        if (p * p > x) break;
        if (x % p) continue;
        res.PB(p);
        while(x%p==0)x /= p;
        if (x == 1) break;
    }
    if (x > 1) res.PB(x);
    return res;
}
 
int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 2, MAXN)
    {
        if (sp[i] == 0)
        {
            sp[i] = i;
            primes.PB(i);
        }
        for (int p : primes)
        {
            if (p > sp[i] || p * i >= MAXN) break;
            sp[p * i] = p;
        }
    }
    FOR(i, 0, N)
    {
        cin >> arr[i];
    }
    FOR(i, 1, N)
    {
        swap(arr[i], arr[randomize(i + 1)]);
    }
    ans = N;
    for (int p : primes)
    {
        if (p > 1013) break;
        ckmin(ans, test(p));
    }
    int iter = 0;
    while(iter < N && clock() / (CLOCKS_PER_SEC / 1000) < 2400)
    {
        vi v; ll x;
        x = arr[iter]; v = getfactors(x);
        for (int p : v)
        {
            if (p <= 1013) continue;
            ckmin(ans, test(p));
        }
        x = arr[iter] - 1; v = getfactors(x);
        for (int p : v)
        {
            if (p <= 1013) continue;
            ckmin(ans, test(p));
        }
        x = arr[iter] + 1; v = getfactors(x);
        for (int p : v)
        {
            if (p <= 1013) continue;
            ckmin(ans, test(p));
        }
        iter++;
    }
    cout << ans << '\n';
    return 0;
}
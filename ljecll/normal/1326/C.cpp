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

const int MAXN = 200013;
const int INF = 998244353;

int add(int a, int b)
{
    a += b; if (a >= INF) a -= INF; return a;
}
int mul(int a, int b)
{
    return (ll) a * b % INF;
}
int sub(int a, int b)
{
    a -= b; if (a < 0) a += INF; return a;
}
int pwr(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if (b & 1) res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}
int inv(int a)
{
    return pwr(a, INF - 2);
}
int dvd(int a, int b)
{
    return mul(a, inv(b));
}

int N, K;
vi pos;
int ans = 1;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    FOR(i, 0, N)
    {
        int x; cin >> x; x = N - x;
        if (x < K)
        {
            // cerr << x << " PB " << i << endl;
            pos.PB(i);
        }
    }
    FOR(i, 0, SZ(pos) - 1)
    {
        ans = mul(ans, pos[i + 1] - pos[i]);
    }
    cout << (ll)(2 * N - K + 1) * K / 2 << ' ' <<  ans << '\n';
    return 0;
}
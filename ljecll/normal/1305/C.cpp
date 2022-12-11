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

int N, M;
ll freq[MAXN];
int arr[MAXN];
int ans = 1;

int add(int a, int b)
{
    a += b; if (a >= M) a -= M;
    return a;
}
int sub(int a, int b)
{
    a -= b; if (a < 0) a += M;
    return a;
}
int mul(int a, int b)
{
    return (ll) a * b % M;
}
int pwr(int a, ll b)
{
    int res = 1;
    while(b)
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    FOR(i, 0, N)
    {
        int x;
        cin >> x;
        freq[x % M]++;
        arr[i] = x;
    }
    sort(arr, arr + N);
    FOR(i, 0, M)
    {
        if (freq[i] >= 2)
        {
            cout << "0\n";
            return 0;
        }
    }
    FOR(i, 0, N)
    {
        FOR(j, i + 1, N)
        {
            ans = mul(ans, (arr[j] - arr[i]) % M);
        }
    }
    cout << ans << '\n';
    return 0;
}
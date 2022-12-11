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

const int MAXN = 300013;
const ll LLINF = 3696969696969696969ll;

int TC;
int N[3];
vl arr[3];
ll ans;

ll test(ll x, ll y, ll z)
{
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
ll solve(vl a, vl b, vl c)
{
    ll res = LLINF;
    int iter = 0, iter1 = 0;
    FOR(i, 0, SZ(a))
    {
        while(iter + 1 < SZ(b) && b[iter + 1] <= a[i])
        {
            iter++;
        }
        while(iter1 + 1 < SZ(c) && c[iter1] < a[i])
        {
            iter1++;
        }
        ckmin(res, test(a[i], b[iter], c[iter1]));
    }
    return res;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        ans = LLINF;
        FOR(i, 0, 3)
        {
            cin >> N[i];
        }
        FOR(i, 0, 3)
        {
            arr[i].resize(N[i]);
            FOR(j, 0, N[i])
            {
                cin >> arr[i][j];
            }
            sort(ALL(arr[i]));
        }
        FOR(i, 0, 3)
        {
            FOR(j, 0, 3)
            {
                if (i == j) continue;
                ckmin(ans, solve(arr[i], arr[j], arr[3 - i - j]));
            }
        }
        cout << ans << '\n';
    }
}
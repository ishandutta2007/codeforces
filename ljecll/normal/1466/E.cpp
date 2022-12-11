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

const int MAXN = 5e5 + 13;
const ll INF = 1e9 + 7;

int TC, N;
ll arr[MAXN];
ll ans;
ll cnt[62];

// #warning check overflow

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        ans = 0;
        FOR(i, 0, 61) cnt[i] = 0;
        cin >> N;
        FOR(i, 0, N)
        {
            cin >> arr[i];
            FOR(j, 0, 61)
            {
                if (arr[i] & (1ll << j)) cnt[j]++;
            }
        }
        FOR(i, 0, N)
        {
            ll s1 = 0, s2 = 0;
            //find the sum of all (ai & aj)
            FOR(j, 0, 61)
            {
                if (!(arr[i] & (1ll << j))) continue;
                s1 += ((1ll << j) % INF) * cnt[j];
                s1 %= INF;
            }
            //find the sum of all (ai | aj)
            FOR(j, 0, 61)
            {
                s2 += ((1ll << j) % INF) * N;
                s2 %= INF;
                if (arr[i] & (1ll << j)) continue;
                s2 -= ((1ll << j) % INF) * (N - cnt[j]);
                s2 %= INF;
                if (s2 < 0) s2 += INF;
            }
            ans += (s1 * s2);
            ans %= INF;
        }
        cout << ans << '\n';
    }
    return 0;
}
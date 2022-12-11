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

int TC, N;
ll S, T;
vl ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        ans.clear();
        S = 0; T = 0;
        cin >> N;
        FOR(i, 0, N)
        {
            int x; cin >> x;
            S += x;
            T ^= x;
        }
        if (S & 1)
        {
            ans.PB((1ll << 50) + 1);
            S += ((1ll << 50) + 1);
            T ^= ((1ll << 50) + 1);
        }
        else
        {
            ans.PB((1ll << 50));
            S += ((1ll << 50));
            T ^= (1ll << 50);
        }
        T *= 2;
        ans.PB((T - S) / 2);
        ans.PB((T - S) / 2);
        cout << 3 << '\n' << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
    return 0;
}
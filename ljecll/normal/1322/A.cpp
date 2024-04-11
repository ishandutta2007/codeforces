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

const int MAXN = 1000013;

int N;
int arr[MAXN];
int pref[MAXN];
vi pos;
int ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    string temps; cin >> temps;
    FOR(i, 0, N)
    {
        arr[i] = (temps[i] == '(' ? 1 : -1);
        pref[i + 1] = pref[i] + arr[i];
    }
    if (pref[N] != 0)
    {
        cout << "-1\n";
        return 0;
    }
    //find the positions where it's 0
    FOR(i, 0, N + 1)
    {
        if (pref[i] == 0) pos.PB(i);
    }
    FOR(i, 1, SZ(pos))
    {
        int x = pos[i - 1], y = pos[i];
        if (arr[x] == -1)
        {
            ans += (y - x);
        }
    }
    cout << ans << '\n';
    return 0;
    //check all the ranges that are ok ig?
}
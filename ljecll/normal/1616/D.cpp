#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#include <iomanip>

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

const int MAXN = 50013;
const long long LLINF = 3e18;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N;
ll arr[MAXN];
ll pref[MAXN];
int dp[MAXN];
int ans;
ll X;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> N;
        FOR(i, 0, N)
        {
            cin >> arr[i];
        }
        cin >> X;
        ans = 0;
        pref[0] = 0;
        FOR(i, 0, N)
        {
            arr[i] -= X;
            pref[i + 1] = pref[i] + arr[i];
        }
        //dp[i + 1] is always dp[i] or dp[i] + 1
        //when is it dp[i] + 1? when you can maintain the thing
        //so you always want to maintian the shortest "tail"
        ll mx = -LLINF;
        dp[0] = 0;
        FOR(i, 0, N)
        {
            if (pref[i + 1] < mx)
            {
                dp[i + 1] = dp[i];
                mx = -LLINF;
            }
            else
            {
                dp[i + 1] = dp[i] + 1;
                ckmax(mx, pref[i]);
            }
        }
        //find the last thing that's < this
        cout << dp[N] << '\n';
    }
    return 0;
}
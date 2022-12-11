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
#define MAXN 3513
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N, M, K;
int arr[MAXN];
int mnl[MAXN], mnr[MAXN];

int solve(int L, int R)
{
    //what's the min they can force you into for [L...R]?
    //they have M-K turns, and then you can delete.
    int mn = INF;
    mnl[L] = arr[L];
    FOR(i, L + 1, R + 1)
    {
        mnl[i] = min(mnl[i - 1], arr[i]);
    }
    mnr[R] = arr[R];
    FORD(i, R, L)
    {
        mnr[i] = min(mnr[i + 1], arr[i]);
    }
    FOR(i, 0, M + 1)
    {
        // cerr << L + i << ' ' << R - (M - i) << endl;
        ckmin(mn, max(arr[L + i], arr[R - (M - i)]));
    }
    // cerr << "mn = " << mn << endl;
    return mn;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cout << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> N >> M >> K;
        FOR(i, 0, N)
        {
            cin >> arr[i];
        }
        M--;
        ckmin(K, M);
        M -= K;
        int ans = -1;
        FOR(i, 0, K + 1)
        {
            //force i people to take left
            //consider the subarray arr[i]...arr[i+(N-K) - 1]
            //what's the min they can force you into?
            ckmax(ans, solve(i, i + N - K - 1));
            // cerr << "solve " << i << ' ' << i + N - K - 1 << ' ' << solve(i, i + N - K - 1) << endl;
        }
        cout << ans << '\n';
        //well meh, can you get this shit to work?
        //remove any of the first K, then
    }
    return 0;
}
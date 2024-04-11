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
#define MAXN 400013
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
int N;
pii arr[MAXN];
int pref[MAXN], pref1[MAXN];
int ans;
vi compress;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> N;
        if (N == 2)
        {
            cin >> N >> N >> N >> N;
            cout << "1\n";
            continue;
        }
        compress.clear();
        FOR(i, 0, N)
        {
            cin >> arr[i].fi >> arr[i].se;
            arr[i].fi *= 2; arr[i].se *= 2; arr[i].se++;
            compress.PB(arr[i].fi); compress.PB(arr[i].se);
        }
        sort(ALL(compress)); compress.erase(unique(ALL(compress)), compress.end());
        sort(arr, arr + N);
        ans = -1;
        FOR(i, 0, SZ(compress) + 1)
        {
            pref[i] = 0;
            pref1[i] = 0;
        }
        multiset<int> singles;
        FOR(i, 0, N)
        {
            arr[i].fi = LB(ALL(compress), arr[i].fi) - compress.begin();
            arr[i].se = LB(ALL(compress), arr[i].se) - compress.begin();
            pref[arr[i].fi]++; pref[arr[i].se]--;
            // cerr << arr[i].fi << " -> " << arr[i].se << endl;
        }
        FOR(i, 1, SZ(compress))
        {
            pref[i] += pref[i - 1];
        }
        FOR(i, 0, SZ(compress))
        {
            pref1[i + 1] = pref1[i] + (pref[i] == 1);
        }
        FOR(i, 0, N)
        {
            // if (arr[i].fi == arr[i].se) continue;
            int gain = pref1[arr[i].se] - pref1[arr[i].fi];
            // cerr << "GAIN " << gain << endl;
            // cerr << pref[arr[i].fi] << ' ' << pref[arr[i].se - 1] << endl;
            if ((arr[i].fi == 0 || pref[arr[i].fi - 1] == 0) && pref[arr[i].fi] == 1) gain--;
            if ((pref[arr[i].se] == 0) && pref[arr[i].se - 1] == 1) gain--;
            ckmax(ans, gain);
            // cerr << "GAIN " << gain << endl;
        }
        // cerr << ans << endl;
        FOR(i, 0, SZ(compress))
        {
            // cerr << pref[i] << ' ';
            if (pref[i] == 0)
            {
                ans++;
                // cerr << "PLUS\n";
            }
        }
        // cerr << endl;
        //now we just have the special case.
        // int mx = 0, c = 0;
        // FOR(i, 2, N)
        // {
        //     if (arr[i].fi > mx) c++;
        //     ckmax(mx, arr[i].se);
        // }
        // ckmax(ans, c);
        //ehh just how many 1's are in this range
        cout << ans << '\n';
        //consider getting a new split between i and i + 1.
        //bj < aj+1
    }
    return 0;
}
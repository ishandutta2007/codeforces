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
#define MAXN 300013
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
int grid[MAXN][9];
int mask[MAXN];
int freq[256], sos[256];
vi guys[256];
pii ans;

bool check(int x)
{
    FOR(i, 0, (1 << M)) freq[i] = 0;
    FOR(i, 0, N)
    {
        int cur = 0;
        mask[i] = 0;
        FOR(j, 0, M)
        {
            if (grid[i][j] >= x) mask[i] += (1 << j);
        }
        freq[mask[i]]++;
    }
    if (freq[(1 << M) - 1] >= 1) return true;
    FOR(i, 0, (1 << M))
    {
        sos[i] = freq[i];
    }
    FOR(i, 0, M)
    {
        FORD(j, (1 << M), 0)
        {
            if (j & (1 << i)) continue;
            sos[j] += sos[j + (1 << i)];
        }
    }
    FOR(i, 0, (1 << M))
    {
        if (freq[i] && sos[((1 << M) - 1) ^ i]) return true;
    }
    return false;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    FOR(i, 0, N)
    {
        FOR(j, 0, M)
        {
            cin >> grid[i][j];
        }
    }
    int lo = 0, hi = INF;
    while(hi > lo)
    {
        int mid = (hi + lo + 1) >> 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    check(lo);
    FOR(i, 0, N)
    {
        // cerr << mask[i] << ' ';
        guys[mask[i]].PB(i);
    }
    // cerr << endl;
    FOR(i, 0, (1 << M))
    {
        if (guys[i].empty()) continue;
        bool res = false;
        FOR(j, i, (1 << M))
        {
            if (guys[j].empty()) continue;
            // cerr << "chk " << i << ' ' << j << endl;
            if ((i | j) != ((1 << M) - 1)) continue;
            // cerr << "chk1 " << i << ' ' << j << endl;
            if (i == j && SZ(guys[i]) < 2) continue;
            // cerr << i << ',' << j << endl;
            res = true;
            ans.fi = guys[i].back(); guys[i].pop_back();
            ans.se = guys[j].back(); guys[j].pop_back();
            break;
        }
        if (res) break;
    }
    cout << ans.fi + 1 << ' ' << ans.se + 1 << '\n';
    return 0;
}
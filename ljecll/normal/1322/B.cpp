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

const int MAXN = 400013;

int N;
int arr[MAXN];
int freq[2][20000007];
int ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> arr[i];
    }
    FOR(i, 0, 25)
    {
        FOR(j, 0, (1 << i) + 1)
        {
            freq[0][j] = 0;
            freq[1][j] = 0;
        }
        FOR(j, 0, N)
        {
            int x = arr[j];
            int b = (x >> i) & 1;
            int r = (x & ((1 << i) - 1));
            // cerr << b << ' ' << r << endl;
            freq[b][r + 1]++;
            //the value that x provides is
        }
        FOR(j, 1, (1 << i) + 1)
        {
            freq[0][j] += freq[0][j - 1];
            freq[1][j] += freq[1][j - 1];
        }
        ll k = 0;
        FOR(j, 0, N)
        {
            int x = arr[j];
            int b = (x >> i) & 1;
            int r = (x & ((1 << i) - 1));
            //1 and carry
            //0 and nocarry
            k += (freq[b][(1 << i)] - freq[b][(1 << i) - r]);
            k += freq[b ^ 1][(1 << i) - r];
        }
        FOR(j, 0, N)
        {
            if ((arr[j] + arr[j]) & (1 << i)) k--;
        }
        k >>= 1;
        // cerr << k << endl;
        if (k & 1) ans += (1 << i);
    }
    cout << ans << '\n';
    return 0;
}
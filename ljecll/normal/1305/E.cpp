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

const int MAXN = 5000;

int N, M;
int ans[MAXN];

int mx(int n)
{
    if (n & 1)
    {
        return mx(n - 1) + (n >> 1) - 1;
    }
    return (n >> 1) * ((n >> 1) - 1);
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    if (M == 0)
    {
        FOR(i, 0, N)
        {
            cout << N + 1 + i << ' ';
        }
        return 0;
    }
    if (M > mx(N))
    {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (M < (i / 2))
        {
            //we've had 1234...i. now we want exactly M pairs. tht's done w
            //i&(i-2M), i-1&
            ans[i] = (i + 1) + (i - 2 * M);
            //now everybody else just goes into outer space
            //just choose #s that are two mod 5
            int it = 12;
            FOR(j, i + 1, N)
            {
                ans[j] = it * (N + 1);
                it += 10;
            }
            break;
        }
        ans[i] = i + 1;
        M -= (i / 2);
    }
    FOR(i, 0, N)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    // int chk = 0;
    // FOR(i, 0, N)
    // {
    //     FOR(j, i + 1, N)
    //     {
    //         FOR(k, j + 1, N)
    //         {
    //             if (ans[i] + ans[j] == ans[k]) chk++;
    //         }
    //     }
    // }
    // cerr << "chk = " << chk << endl;
    return 0;
}
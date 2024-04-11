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
#define MAXN 113

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, N, D;
int arr[MAXN];

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        int sum = 0;
        cin >> N >> D;
        FOR(i, 0, N)
        {
            cin >> arr[i];
        }
        while(D > 0)
        {
            FOR(i, 1, N + 1)
            {
                if (i > D || i == N)
                {
                    D = 0;
                    break;
                }
                if (arr[i] == 0) continue;
                arr[0]++;
                arr[i]--;
                D -= i;
                break;
            }
        }
        cout << arr[0] << '\n';
    }
    return 0;
}
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
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, Q;
int arr[MAXN];
int freq[28][MAXN];

int32_t main()
{
    cout << fixed << setprecision(12);
    cout << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    string temps; cin >> temps;
    N = SZ(temps);
    FOR(i, 0, N)
    {
        arr[i] = (temps[i] - 'a' + 1);
        FOR(j, 0, 27)
        {
            freq[j][i + 1] = freq[j][i] + (arr[i] == j);
        }
    }
    cin >> Q;
    while(Q--)
    {
        int L, R;
        cin >> L >> R; L--; R--;
        if (L == R)
        {
            cout << "Yes\n";
            continue;
        }
        int letters = 0;
        FOR(j, 0, 27)
        {
            if (freq[j][R + 1] - freq[j][L])
            {
                letters++;
            }
        }
        //# of distinct letters has to be >= 2?
        cout << ((letters > 2 || arr[L] != arr[R]) ? "Yes" : "No") << "\n";
    }
    return 0;
}
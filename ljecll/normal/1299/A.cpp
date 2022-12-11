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

const int MAXN = 100013;

int N;
int arr[MAXN];
int freq[31];
int mx, idx;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> arr[i];
        FOR(j, 0, 30)
        {
            if (arr[i] & (1 << j))
            {
                freq[j]++;
            }
        }
    }
    FOR(i, 0, N)
    {
        int val = 0;
        FOR(j, 0, 30)
        {
            if (!(arr[i] & (1 << j))) continue;
            if (freq[j] == 1) val += (1 << j);
        }
        if (val > mx)
        {
            mx = val;
            idx = i;
        }
    }
    if (idx != 0) swap(arr[0], arr[idx]);
    //this one must have the bit on and everybody else does not.
    FOR(i, 0, N)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
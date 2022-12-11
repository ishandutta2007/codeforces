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

const int MAXN = 75;

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
int arr[MAXN];

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        //longest arithmetic sequence.
        cin >> N;
        FOR(i, 0, N)
        {
            cin >> arr[i];
        }
        int res = 1;
        FOR(i, 0, N)
        {
            FOR(j, i + 1, N)
            {
                int cur = 0;
                //see how many this works!
                FOR(k, 0, N)
                {
                    if (k == i || k == j)
                    {
                        cur++;
                        continue;
                    }
                    if ((arr[k] - arr[i]) * (k - j) == (k - i) * (arr[k] - arr[j]))
                    {
                        cur++;
                    }
                }
                ckmax(res, cur);
            }
        }
        cout << N - res << '\n';
    }
    return 0;
}
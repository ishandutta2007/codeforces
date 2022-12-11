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

const int MAXN = 113;
const int INF = 1e9 + 7;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, N;
int arr[MAXN];

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
        int ans = INF;
        FOR(i, 0, 7)
        {
            FOR(j, 0, 7)
            {
                //say we have i 1's, i 2's
                int need = 0;
                FOR(n, 0, N)
                {
                    int cur = INF;
                    FOR(k, 0, i + 1)
                    {
                        FOR(m, 0, j + 1)
                        {
                            int c = arr[n] - k * 1 - m * 2;
                            if (c >= 0 && c % 3 == 0)
                            {
                                ckmin(cur, c / 3);
                            }
                        }
                    }
                    ckmax(need, cur);
                }
                ckmin(ans, need + i + j);
                // if (need + i + j == 3) cerr << i << ' ' << j << ' ' << need << endl;
            }
        }
        cout << ans << '\n';
        //we def won't need more than say, 6 1's or 6 2's, so say let's brute force
    }
    return 0;
}
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        int a;
        ll b, c;
        cin >> a >> b >> c;
        string s; cin >> s;
        vpi blocks;
        c--;
        for (char c : s)
        {
            bool b = (c == '*');
            if (!blocks.empty() && b == blocks.back().se)
            {
                blocks.back().fi++;
            }
            else
            {
                blocks.PB(MP(1, b));
            }
        }
        vi nums;
        for (auto p : blocks)
        {
            if (p.se)
            {
                nums.PB(p.fi);
            }
        }
        reverse(ALL(nums));
        vi res;
        for (int x : nums)
        {
            int cnt = x * b + 1;
            res.PB(c % cnt);
            c /= cnt;
        }
        for (pii p : blocks)
        {
            if (p.se)
            {
                FOR(j, 0, res.back())
                {
                    cout << 'b';
                }
                res.pop_back();
            }
            else
            {
                FOR(j, 0, p.fi)
                {
                    cout << 'a';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
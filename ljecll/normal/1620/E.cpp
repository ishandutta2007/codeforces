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

const int MAXN = 5e5 + 13;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
int quer[MAXN][3];
int go[MAXN];
vi ans;


int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            quer[i][0] = x; quer[i][1] = y;
        }
        if (x == 2)
        {
            int y, z;
            cin >> y >> z;
            quer[i][0] = x; quer[i][1] = y; quer[i][2] = z;
        }
    }
    iota(go, go + MAXN, 0);
    FORD(i, N, 0)
    {
        if (quer[i][0] == 1)
        {
            int c = quer[i][1];
            ans.PB(go[c]);
            //then you just add a wherever
        }
        if (quer[i][0] == 2)
        {
            int y = quer[i][1], z = quer[i][2];
            go[y] = go[z];
            //more complicated. y now goes to wherever z goes.
        }
    }
    reverse(ALL(ans));
    for (int x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
    //find the last place where everybody goes.
    return 0;
}
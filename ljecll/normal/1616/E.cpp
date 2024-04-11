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

const int MAXN = 1e5 + 13;
const long long LLINF = 3e18;

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
string s, t;
vi pos[28];
ll fen[MAXN];
ll ans;

void init()
{
    fill(fen, fen + N + 2, 0);
}
void update(int idx, ll v)
{
    for (int e = idx + 1; e < N + 2; e += e & (-e))
    {
        fen[e] += v;
    }
}
ll query(int idx)
{
    ll res = 0;
    for (int e = idx + 1; e; e -= e & (-e))
    {
        res += fen[e];
    }
    return res;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> N >> s >> t;
        string tmp = s;
        sort(ALL(tmp));
        if (tmp >= t)
        {
            cout << "-1\n";
            continue;
        }
        // cerr << "HELLO\n";
        FOR(i, 0, 26)
        {
            pos[i].clear();
        }
        FOR(i, 0, SZ(s))
        {
            pos[s[i] - 'a'].PB(i);
        }
        FOR(i, 0, 26)
        {
            reverse(ALL(pos[i]));
        }
        // cerr << "GOODBYE\n";
        init();
        FOR(i, 0, N)
        {
            update(i, 1);
        }
        ll cur = 0;
        ans = LLINF;
        FOR(i, 0, N)
        {
            //ok now let's try to beat t[i]!
            FOR(j, 0, t[i] - 'a')
            {
                if (pos[j].empty())
                {
                    continue;
                }
                int c = pos[j].back();
                int actual = i + query(c) - 1;
                ckmin(ans, cur + (actual - i));
            }
            //to get the current location of a c, you do i + (# of things on before c)
            int j = t[i] - 'a';
            if (pos[j].empty()) break;
            int c = pos[j].back();
            int actual = i + query(c) - 1;
            cur += (actual - i);
            update(c, -1);
            // cerr << "get " << c << ' ' << cur << endl;
            pos[j].pop_back();
            //find the thin
            //find the thing that's currently at
        }
        cout << ans << '\n';
        //suppose you're trying to beat bbccb
        //then either you just get the first thing < b that's still ahead.
        //otherwise, you get the first b.
    }
    return 0;
}
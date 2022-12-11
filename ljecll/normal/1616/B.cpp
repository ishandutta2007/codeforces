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
string s;

string get(int c)
{
    string res = "";
    FOR(i, 0, c + 1)
    {
        res += s[i];
    }
    FORD(i, c + 1, 0)
    {
        res += s[i];
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
        int n; cin >> n;
        cin >> s;
        string res = get(0);
        // int idx = 0;
        // FOR(i, 0, n)
        // {
        //     if (i == n - 1 || s[i] < s[i + 1])
        //     {
        //         idx = i;
        //         break;
        //     }
        // }
        // //you can choose a char if it's != the previous one??
        // FOR(i, 0, idx + 1)
        // {
        //     if (i == 0 || s[i] != s[i - 1])
        //     {
        //         string cur = get(i);
        //         res = min(res, cur);
        //     }
        // }
        //if they're equal and you have two distinct characters it helps.
        //if it's smaller, then it helps
        // set<char> st;
        int idx = 0;
        for (idx = 0; idx < n; idx++)
        {
            if (idx != 0 && s[idx] > s[idx - 1]) break;
            // if (idx != 0 && s[idx] == s[idx - 1] && SZ(st) <= 1) break;
            // st.insert(s[idx]);
        }
        ckmin(res, get(idx - 1));
        cout << res << '\n';
        //now take everything until you get equal to s[i]
    }
    //keep on taking it as it decreases. and if there's smth that decreases further, also take that.
    //find the first place where it increases
    return 0;
}
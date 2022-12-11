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

string s;
vi pos;
vi ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    FOR(i, 0, SZ(s))
    {
        if (s[i] == ')')
        {
            pos.PB(i);
        }
    }
    FOR(i, 0, SZ(s))
    {
        if (s[i] == '(')
        {
            if (!pos.empty() && pos.back() > i)
            {
                ans.PB(i);
                ans.PB(pos.back());
                pos.pop_back();
            }
        }
    }
    sort(ALL(ans));
    if (ans.empty())
    {
        cout << "0\n";
        return 0;
    }
    cout << "1\n" << SZ(ans) << '\n';
    for (int x : ans)
    {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}
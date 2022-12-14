#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    string s;
    cin >> s;

    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;
    int curx = 0;
    int cury = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'U') --cury;
        if (s[i] == 'D') ++cury;
        if (s[i] == 'L') --curx;
        if (s[i] == 'R') ++curx;

        if (max(curx, xmax) - min(curx, xmin) >= m || max(cury, ymax) - min(cury, ymin) >= n)
        {
            cout << 1 - ymin << " " << 1 - xmin << endl;
            return 0;
        }

        xmax = max(curx, xmax);
        xmin = min(curx, xmin);
        ymax = max(cury, ymax);
        ymin = min(cury, ymin);
    }




            cout << 1 - ymin << " " << 1 - xmin << endl;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
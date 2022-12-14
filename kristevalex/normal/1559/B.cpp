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
    cin >> n;

    string s;
    cin >> s;

    int tp = 0;
    for (int i = n-1; i >= 0; --i)
    {
        if (s[i] == 'R')
            tp = i%2;
        else if(s[i] == 'B')
            tp = (i+1)%2;
    }

    s[0] = 'R';
    if (tp == 1)
        s[0] = 'B';
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == '?')
        {
            if (s[i-1] == 'B')
                s[i] = 'R';
            else
                s[i] = 'B';
        }
    }




    cout << s << endl;

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
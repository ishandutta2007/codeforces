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

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    string type;
    cin >> type;

    vi B;
    vi R;

    for (int i = 0; i < n; ++i)
    {
        if (type[i] == 'B')
        {
            B.pb(::data[i]);
        }
        else
            R.pb(n+1-::data[i]);
    }

    sort(all(R));
    sort(all(B));

    for (int i = 0; i < R.size(); ++i)
    {
        if (R[i] <= i)
        {
            cno;
            return 0;
        }
    }

    for (int i = 0; i < B.size(); ++i)
    {
        if (B[i] <= i)
        {
            cno;
            return 0;
        }
    }



cyes;

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
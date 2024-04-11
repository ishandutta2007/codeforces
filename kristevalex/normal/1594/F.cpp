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
    cin >> n >> m >> k;


    if (n == k)
    {
        cyes;
        return 0;
    }

    if (n < k)
    {
        cno;
        return 0;
    }

    if (k == 1)
    {
        if (n >= 2 * m)
            cno;
        else
            cyes;

        return 0;
    }

    ll tot = (n+k+1)/(2*k);
    tot *= 2*k;

    ll left = n+ k +1- tot;
    left -= k;
    left = max(left, 0ll);
    tot += 2*left;

    //cout << n + k << " " << tot;

    if (2*(m+1) > tot)
        cyes;
    else
        cno;

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
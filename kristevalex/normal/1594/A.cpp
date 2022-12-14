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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define cendl cout << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;


    ll sz = 1;

    while(n % 2 == 0)
    {
        sz *= 2;
        n /= 2;
    }

    n/= 2;





    cout << n - sz + 1 << " " << n + sz << endl;

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
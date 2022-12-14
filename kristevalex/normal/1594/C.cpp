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
    char c;
    cin >> n >> c;


    string dt;
    cin >> dt;

    bool is_samev = true;
    for (int i = 0; i < n; ++i)
    {
     if (dt[i] != c)
            is_samev = false;
    }

    if (is_samev)
    {
        cout << 0 << endl;
        return 0;
    }

    if (dt[n-1] == c)
    {
        cout << 1 << endl << n << endl;
        return 0;
    }



    for (int i = n; i >= n/2 + 1; --i)
    {
        if (dt[i-1] == c)
        {

        cout << 1 << endl << i << endl;
        return 0;
        }
    }




    cout << 2 << endl << n-1 << " " << n << endl;

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
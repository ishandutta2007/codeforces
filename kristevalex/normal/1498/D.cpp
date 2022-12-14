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
#define ft first
#define sd second
#define cendl cout << endl


vi data;

long long a, b, k, n, m, tmp, ans = 0;

ll get1(ll cur, ll x)
{
    return cur + (x + 99999) / 100000;
}

void type1(ll x, ll y, ll id, ll new_val)
{
    if (y < 0) return;
    if (id <= 0 || id > m) return;
    if (::data[id] != -1) return;

    ::data[id] = new_val;
    type1(x, y-1, get1(id, x), new_val);
}

ll get2(ll cur, ll x)
{
    return (cur * x + 99999) / 100000;
}


void type2(ll x, ll y, ll id, ll new_val)
{
    if (y < 0) return;
    if (id <= 0 || id > m) return;
    if (::data[id] != -1) return;

    ::data[id] = new_val;
    type2(x, y-1, get2(id, x), new_val);
}



int solve()
{
    cin >> n >> m;

    ::data.resize(m+1, -1);

    ::data[0] = 0;

    ll x, y, type;

    for (int i = 0; i < n; ++i)
    {
        cin >> type >> x >> y;

        for (int j = 0; j <= m; ++j)
        {
            if (::data[j] != -1 && ::data[j] != i + 1)
            {
                if (type == 1)
                    type1(x, y-1, get1(j, x), i + 1);
                else
                    type2(x, y-1, get2(j, x), i + 1);
            }
        }
    }




    for (int i = 1; i <= m; ++i)
    {
        cout << ::data[i] << " ";
    }
    cendl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
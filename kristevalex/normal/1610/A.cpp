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

    if (n == 1 && m == 1)
        cout << 0 << endl;
    else if (n == 1 || m == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;

    return 0;
}


int main()
{
    FAST;

int data[3000][3000][2];
    for (int i = 0; i < 3000; ++i)
    {
        for (int j = 0; j < 3000; ++j)
        {
            data[i][j][0] = -1;
            data[i][j][1] = -1;
        }
    }

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
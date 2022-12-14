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
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);
    vi res(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];
    for (int i = 0; i < n; ++i)
        cin >> res[i];

    vi cnt(n+1, 0);


    int curres = 0;
    for (int i = 0; i < n; ++i)
    {
        int resvl = res[curres];
        if (data[i] == resvl)
        {
            ++curres;
            while(curres < n && (res[curres] == resvl && cnt[resvl] > 0))
            {
                ++curres;
                cnt[resvl]--;
            }
        }
        else
        {
            cnt[data[i]]++;
        }
    }




    if (curres == n)
    {
        cyes;
        return 0;
    }

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
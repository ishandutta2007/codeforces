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

vector<int> primes;
vector<vector<pii>> decomposition;
vector<int> left;

void SetupPrimes(int upTo)
{
    decomposition.resize(upTo + 1);
    ::left.resize(upTo + 1);

    for (int i = 0; i < ::left.size(); ++i)
        ::left[i] = i;

    for (int i = 2; i <= upTo; ++i)
    {
        if (decomposition[i].size() == 0)
        {
            decomposition[i].pb({i, 1});
            primes.push_back(i);
            if (i * 1ll * i <= upTo)
            {
                for (int j = i*i; j <= upTo; j += i)
                {
                    int pw = 0;
                    while(::left[j] % i == 0)
                    {
                        ::left[j] /= i;
                        ++pw;
                    }
                    decomposition[j].pb({i, pw});
                }
            }
        }
    }
}

int solve()
{

    cin >> n;

    ::data.resize(n);

    for (int i = 2; i <= n+1; ++i)
    {
        cout << i << " ";
    }
    cendl;

    return 0;
}


int main()
{
    SetupPrimes(1000000);
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
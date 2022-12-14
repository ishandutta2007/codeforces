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

bool is_possible(int len)
{
    vector<bool> curpossible(len+1, true);
    vector<bool> nextpossible(len+1);

    for (int i = 0; i < n; ++i)
    {
        nextpossible.assign(len+1, false);
        for (int j = 0; j < curpossible.size(); ++j)
        {
            if (curpossible[j])
            {
                if (j + ::data[i] <= len)
                    nextpossible[j + ::data[i]] = true;
                if (j - ::data[i] >= 0)
                    nextpossible[j - ::data[i]] = true;
            }
        }
        curpossible = nextpossible;
    }

    for (int i = 0; i < curpossible.size(); ++i)
        if (curpossible[i])
            return true;

    return false;
}



int solve()
{
    cin >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    int low = 0;
    int high = 2000;
    int mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (is_possible(mid))
            high = mid;
        else
            low = mid;
    }


    cout << high << endl;

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
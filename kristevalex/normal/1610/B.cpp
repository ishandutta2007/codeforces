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

bool Check(int del)
{
    int i = 0;
    int j = n-1;
    while(i < j)
    {
        while(i < n)
        {
            if (::data[i] != del)
                break;
            ++i;
        }

        while(j >= 0)
        {
            if (::data[j] != del)
                break;
            --j;
        }

        if (i >= j)
            break;

        if (::data[i] != ::data[j])
        {
            return false;
        }

        ++i;
        --j;
    }

    return true;
}

int solve()
{
    cin >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];


    bool ok=true;
    for (int i = 0; i <= n/2; ++i)
    {
        if (::data[i] != ::data[n-i-1])
        {
            a = ::data[i];
            b = ::data[n-i-1];
            ok = false;
            break;
        }
    }

    if (ok)
    {
        cyes;
        return 0;
    }



if (Check(a) || Check(b))
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
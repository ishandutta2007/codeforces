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


vector<int> data;

long long a, b, k, n, m, tmp, ans = 0;


int GetDist(vector<int> perm, int offset)
{
    int dist = 0;

    for (int i = 0; i < n; )
    {
        if (perm[i] == (i+offset)%n)
        {
            ++i;
            continue;
        }

        int j = perm[i] + n - offset;
        j %= n;

        int tmp = perm[j];
        perm[j] = perm[i];
        perm[i] = tmp;
        ++dist;
    }

    return dist;
}



int solve()
{
    cin >> n >> m;

    ::data.resize(n);
    vi cnt(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i];
        ::data[i]--;
        cnt[(::data[i] + n - i)%n]++;
    }

    vi as(0);
    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] + 2 * m >= n)
        {
            if (GetDist(::data, i) <= m)
            {
                as.push_back((n-i)%n);
            }
        }
    }

    sort(all(as));




    cout << as.size() << endl;
    for (int i = 0; i < as.size(); ++i)
    {
        cout << as[i] << " ";
    }
    cendl;


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
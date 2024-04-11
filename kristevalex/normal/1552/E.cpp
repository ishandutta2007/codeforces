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
    cin >> n >> k;
    int maxx = (n+k-2)/(k-1);

    vi last(n, -1);

    vi used(n*k, 0);

    vpii as(n);

    int first_allowed = 0;

    for (int i = 0; i < n*k; ++i)
    {
        int x;
        cin >> x;
        --x;

        if (last[x] == -2)
            continue;


        if (last[x] == -1)
        {
            last[x] = i;
            continue;
        }

        if (last[x] >= first_allowed)
        {
            as[x] = {last[x], i};
            for (int j = last[x]; j <= i; ++j)
            {
                used[j]++;
                if (used[j] >= maxx)
                    if (first_allowed < j+1)
                        first_allowed = j+1;
            }

            last[x] = -2;
        }
        else
        {
            last[x] = i;
        }
    }


    for (int i = 0; i < n; ++i)
    {
        cout << as[i].ft+1 << " " << as[i].sd+1 << endl;
    }

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
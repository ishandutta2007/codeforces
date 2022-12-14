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



long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);
    vvi ends(2);

    for (int i = 0; i < n; ++i)
        cin >> data[i];


        int len = 1;
        ends[0].pb(data[0]);
        for ( ; len < n; ++len)
        {
            if (data[len] <= data[len-1])
            {
                break;
            }
            ends[0].pb(data[len]);
        }


        len = 1;
        ends[1].pb(data[n-1]);
        for ( ; len < n; ++len)
        {
            if (data[n-1-len] <= data[n-len])
            {
                break;
            }
            ends[1].pb(data[n-1-len]);
        }

    int curmaxid = 0;
    if (data[n-1] > data[0])
        curmaxid = 1;

    if (ends[curmaxid].size() % 2 == 1)
    {
        cout << "Alice" << endl;
        return 0;
    }

    int curused = 0;

    vi ids(2, 0);

    while(true)
    {
        int curminid = 1 - curmaxid;


        if (ends[curmaxid][ids[curmaxid]] == ends[curminid][ids[curminid]])
        {
            if ((ends[curminid].size() - ids[curminid])%2 == 1)
            {
                if (curused%2 == 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
                return 0;
            }

            if ((ends[curmaxid].size() - ids[curmaxid])%2 == 1)
            {
                if (curused%2 == 0)
                    cout << "Alice" << endl;
                else
                    cout << "Bob" << endl;
                return 0;
            }


            if (curused%2 == 1)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
            return 0;
        }

        for ( ; ids[curminid] < ends[curminid].size(); ++ids[curminid])
        {
            if (ends[curmaxid][ids[curmaxid]] <= ends[curminid][ids[curminid]])
                break;

            curused++;
        }

        if (ids[curminid] == ends[curminid].size())
        {
            if ((curused + ends[curmaxid].size() - ids[curmaxid]) % 2 == 1)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
            return 0;
        }

        if ((ends[curminid].size() - ids[curminid])%2 == 1)
        {
            if (curused%2 == 0)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
            return 0;
        }


        curmaxid = 1 - curmaxid;
    }



    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
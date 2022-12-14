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



long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vector<string> data(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }

    set<int> sts;
    set<int> st3;
    set<int> st2;
    for (int i = 0; i < n; ++i)
    {
        if (data[i].size() == 1)
        {
            cyes;
            return 0;
        }
        if (data[i].size() == 2 && data[i][0] == data[i][1])
        {
            cyes;
            return 0;
        }
        if (data[i].size() == 3 && data[i][0] == data[i][2])
        {
            cyes;
            return 0;
        }
        if (data[i].size() == 2)
        {

            int cr = 0;
            cr += data[i][0] - 'a';
            cr *= 40;
            cr += data[i][1] - 'a';

            sts.insert(cr);

            cr = 0;
            cr += data[i][1] - 'a';
            cr *= 40;
            cr += data[i][0] - 'a';

            if (sts.count(cr) || st2.count(cr))
            {
                cyes;
                return 0;
            }
        }
        else
        {
            int cr = 0;
            cr += data[i][0] - 'a';
            cr *= 40;
            cr += data[i][1] - 'a';

            st2.insert(cr);
            cr *= 40;
            cr += data[i][2] - 'a';
            st3.insert(cr);

            cr = 0;
            cr += data[i][2] - 'a';
            cr *= 40;
            cr += data[i][1] - 'a';

            if (sts.count(cr))
            {
                cyes;
                return 0;
            }
            cr *= 40;
            cr += data[i][0] - 'a';

            if (st3.count(cr))
            {
                cyes;
                return 0;
            }
        }
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
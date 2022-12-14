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



vi lens;
vpii adds;
int offset = 0;

vi tryr(vi data)
{
    int id = 1;
    while (true)
    {
        if (id == data.size())
            return data;

        if (data[id] == data[0])
            break;

        ++id;
    }

    vi dt(data.size()-2);
    for (int i = 1; i < id; ++i)
    {
        dt[id-i-1] = data[i];
    }
    for (int i = id+1; i < data.size(); ++i)
    {
        dt[i-2] = data[i];
    }

    for (int i = 1; i < id; ++i)
    {
        adds.pb({offset + id + i, data[i]});
    }

    lens.pb(id*2);
    offset += id*2;


    return dt;
}


int solve()
{
    cin >> n;
    lens.clear();
    adds.clear();
    offset = 0;


    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    while(true)
    {
        auto dt = tryr(data);
        //log(dt.size());
        if (dt.size() == 0)
            break;
        if (dt.size() == data.size())
        {
            cout << "-1\n";
            return 0;
        }
        data = dt;
    }

    cout << adds.size() << '\n';
    for (int i = 0; i < adds.size(); ++i)
    {
        cout << adds[i].ft << ' ' << adds[i].sd << '\n';
    }
    cout << lens.size() << '\n';
    for (int i = 0; i < lens.size(); ++i)
    {
        cout << lens[i] << ' ';
    }
    cout << '\n';





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
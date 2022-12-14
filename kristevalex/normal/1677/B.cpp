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
    cin >> m >> n;
    string s;
    cin >> s;

    vi data(n*m, 0);

    int sum = 0;
    for (int i = 0; i < n*m; ++i)
    {
        sum += s[i]-'0';
        if (i-n >= 0)
            sum -= s[i-n]-'0';

        if (sum > 0)
            data[i] = 1;
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = i+n; j < n*m; j += n)
        {
            data[j] += data[j-n];
        }
    }

    set<int> st;
    for (int i = 0; i < n; ++i)
    {
        st.insert(i);
    }

    for (int i = 0; i < n*m; ++i)
    {
        if (s[i] == '1')
        {
            if (st.count(i%n))
            {
                st.erase(i%n);
            }
        }

        data[i] += n - st.size();
    }




    for (int i = 0; i < data.size(); ++i)
    {
        cout << data[i] << ' ';
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
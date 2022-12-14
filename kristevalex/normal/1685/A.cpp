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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


/*

3
6
3 2 1 1 0 0
6
2 2 1 1 0 0
6
3 3 2 2 1 1



*/

    int t, t2;

int solve()
{
    cin >> n;

    vi st;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        st.pb(x);

    }


    if (n%2 == 1)
    {
        cno;
        return 0;
    }

    sort(all(st));

    vi s1, s2, s3;

    int cur = st[0];
    int num = 0;

    bool on1 = true;
    bool on2 = true;

    for (int i = 0; i < st.size(); ++i)
    {
        if (cur == st[i])
            ++num;
        else
        {
            if (num + s1.size() <= n/2 && on1)
            {
                for (int j = 0; j < num; ++j)
                {
                    s1.pb(cur);
                }
            }
            else if (num + s2.size() < n/2 && on2)
            {
                for (int j = 0; j < num; ++j)
                {
                    s2.pb(cur);
                }
                on1 = false;
            }
            else
            {
                for (int j = 0; j < num; ++j)
                {
                    s3.pb(cur);
                }
                on2 = false;
                on1 = false;
            }

            cur = st[i];
            num = 1;
        }

        if (num > n/2)
        {
            cno;
            return 0;
        }
    }

    for (int i = 0; i < num; ++i)
    {
        s3.pb(cur);
    }

    /*cout << 1 << ": ";
    for (int i = 0; i < s1.size(); ++i)
    {
        cout << s1[i] << ' ';
    }
    cendl;

    cout << 2 << ": ";
    for (int i = 0; i < s2.size(); ++i)
    {
        cout << s2[i] << ' ';
    }
    cendl;

    cout << 3 << ": ";
    for (int i = 0; i < s3.size(); ++i)
    {
        cout << s3[i] << ' ';
    }
    cendl;*/


    if (s3.size() > n/2)
    {
        cno;
        return 0;
    }



    vi as(n, -1);
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;

    for (int i = 0; i < n; i+=2)
    {
        if (i1 < s1.size())
        {
            as[i] = s1[i1];
            ++i1;
        }
    }

    for (int i = n-1; i >= 0; i-=2)
    {
        if (i3 < s3.size())
        {
            as[i] = s3[i3];
            ++i3;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (as[i] == -1)
        {
            as[i] = s2[i2];
            ++i2;
        }
    }


    cyes;
    for (int i = 0; i < as.size(); ++i)
    {
        cout << as[i] << ' ';
    }
    cendl;






    return 0;
}


int main()
{
    FAST;

    cin >> t;
    t2 = t;


    for (int i = 1; i <= t; ++i)
    {
        t2 = i;
        solve();
    }

    return 0;
}
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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


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
    cin >> n;

    vi dt(n);
    for (int i = 0; i < n; ++i)
    {
        dt[i] = i + 1;
    }

    while(dt.size() > 3)
    {
        //log(dt);
        int i1 = dt.size()/4;
        int i2 = i1 + (dt.size()-i1)/3;
        int i3 = i2 + (dt.size()-i2)/2;

        string a1, a2;

        cout << "? " << i2 << " ";
        for (int i = 0; i < i2; ++i)
        {
            cout << dt[i] << ' ';
        }
        cendl;
        cin >> a1;

        cout << "? " << i3-i1 << " ";
        for (int i = i1; i < i3; ++i)
        {
            cout << dt[i] << ' ';
        }
        cendl;
        cin >> a2;

        if (a1[0] == 'Y' && a2[0] == 'Y')
        {
            vi nxt;
            for (int i = 0; i < i3; ++i)
            {
                nxt.pb(dt[i]);
            }
            //log(nxt);
            dt = nxt;
            //log(dt);
            continue;
        }

        if (a1[0] == 'N' && a2[0] == 'N')
        {
            vi nxt;
            for (int i = 0; i < i1; ++i)
            {
                nxt.pb(dt[i]);
            }
            for (int i = i2; i < dt.size(); ++i)
            {
                nxt.pb(dt[i]);
            }
            //log(nxt);
            dt = nxt;
            //log(dt);
            continue;
        }

        if (a1[0] == 'Y' && a2[0] == 'N')
        {
            vi nxt;
            for (int i = 0; i < i2; ++i)
            {
                nxt.pb(dt[i]);
            }
            for (int i = i3; i < dt.size(); ++i)
            {
                nxt.pb(dt[i]);
            }
            dt = nxt;
            continue;
        }

        if (a1[0] == 'N' && a2[0] == 'Y')
        {
            vi nxt;
            for (int i = i1; i < dt.size(); ++i)
            {
                nxt.pb(dt[i]);
            }
            dt = nxt;
            continue;
        }
    }



    if (dt.size() == 3)
    {
        vi cp = dt;
        vi nxt;
        string a1, a2, a3, a4;

        cout << "? 1 " << dt[2] << endl;
        cin >> a1;
        cout << "? 2 " << dt[2] << ' ' << dt[1] << endl;
        cin >> a2;

        if (a1[0] == 'Y' && a2[0] == 'Y')
        {
            nxt.pb(dt[1]);
            nxt.pb(dt[2]);
            dt = nxt;
        }
        else if (a1[0] == 'N' && a2[0] == 'N')
        {
            nxt.pb(dt[1]);
            nxt.pb(dt[0]);
            dt = nxt;
        }
        else if (a1[0] == 'Y' && a2[0] == 'N')
        {
            nxt.pb(dt[2]);
            nxt.pb(dt[0]);
            dt = nxt;
        }
        else
        {
            cout << "? 1 " << dt[0] << endl;
            cin >> a1;
            cout << "? 2 " << dt[0] << ' ' << dt[1] << endl;
            cin >> a2;


            if (a1[0] == 'Y' && a2[0] == 'Y')
            {
                nxt.pb(dt[0]);
                nxt.pb(dt[1]);
                dt = nxt;
            }
            else if (a1[0] == 'N' && a2[0] == 'N')
            {
                nxt.pb(dt[1]);
                nxt.pb(dt[2]);
                dt = nxt;
            }
            else if (a1[0] == 'Y' && a2[0] == 'N')
            {
                nxt.pb(dt[2]);
                nxt.pb(dt[0]);
                dt = nxt;
            }
            else
            {
                nxt.pb(dt[2]);
                nxt.pb(dt[1]);
                dt = nxt;
            }
        }

    }



    cout << "! " << dt[0] << endl;
    string rsp;
    cin >> rsp;
    if (rsp[1] == '(')
    {
        cout << "! " << dt[1] << endl;
        cin >> rsp;
    }



    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}
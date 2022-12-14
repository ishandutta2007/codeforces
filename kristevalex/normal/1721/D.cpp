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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl



long long k, n, m, tmp, ans = 0;

vvi a(1, vi());
vvi b(1, vi());

bool check_gr(int grid, int mask)
{
    int cnta1 = 0;
    int cntb0 = 0;
    for (int i = 0; i < a[grid].size(); ++i)
    {
        if ((a[grid][i] & mask) != 0)
            ++cnta1;
        if ((b[grid][i] & mask) == 0)
            ++cntb0;
    }

    return cnta1 == cntb0;
}

void divide_gr(int grid, int mask)
{
    vi olda;
    vi newa;
    vi oldb;
    vi newb;

    for (int i = 0; i < a[grid].size(); ++i)
    {
        if ((a[grid][i] & mask) != 0)
            olda.pb(a[grid][i]);
        else
            newa.pb(a[grid][i]);

        if ((b[grid][i] & mask) != 0)
            newb.pb(b[grid][i]);
        else
            oldb.pb(b[grid][i]);
    }

    if (olda.size() == 0 || newa.size() == 0)
        return;

    a[grid] = olda;
    a.pb(newa);
    b[grid] = oldb;
    b.pb(newb);
}



int solve()
{
    cin >> n;

    a.resize(1);
    b.resize(1);

    a[0].resize(n);
    b[0].resize(n);
    cin >> a[0] >> b[0];

    log(a);
    log(b);

    int mask = 1 << 30;
    log(mask);

    ans = 0;

    while(mask > 0)
    {
        bool ok = true;

        for (int i = 0; i < a.size(); ++i)
        {
            ok = (ok && check_gr(i, mask));
        }

        if (ok)
        {
            log(mask);
            ans += mask;
            int sz = a.size();
            log(sz);
            for (int i = 0; i < sz; ++i)
            {
                divide_gr(i, mask);
            }
            log(sz);
        }

        mask /= 2;
    }


    cout << ans << endl;

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
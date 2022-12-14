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

long long a, b, c, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    int maxx = -1;
    int maxid = -1;
    int maxnumx = 0;
    int maxnumy = 0;

    for (int i = 2; i < n; ++i)
    {
        cout << "? 1 2 " << i+1 << endl;
        cin >> ans;

        if (ans > maxx)
        {
            maxx = ans;
            maxid = i;
        }
    }



    int over = 2;
    if (maxid == 2)
        over++;

    int mayx = -1;
    int mayid = -1;

    for (int i = 0; i < n; ++i)
    {
        if (i == over || i == maxid)
            continue;

        //log(i);
        cout << "? " << i+1 << " " << over+1 << " " << maxid+1 << endl;
        cin >> ans;

        if (ans > mayx)
        {
            mayx = ans;
            mayid = i;
            maxnumy = 1;
        }
        else if (ans == mayx)
            ++maxnumy;
    }

    a = 0;
    b = 1;
    c = maxid;
    if (mayx >= maxx)
    {
        a = mayid;
        b = over;
        c = maxid;
    }

    maxx = max(maxx, mayx);
    int d = 0;
    while(d == a || d == b || d == c)
        ++d;

    cout << "? " << a+1 << " " << b+1 << " " << d+1 << endl;
    cin >> ans;
    if (ans == maxx)
    {

        cout << "! " << a+1 << " " << b+1 << endl;
        return 0;
    }

    cout << "? " << a+1 << " " << c+1 << " " << d+1 << endl;
    cin >> ans;
    if (ans == maxx)
    {

        cout << "! " << a+1 << " " << c+1 << endl;
        return 0;
    }




    cout << "! " << b+1 << " " << c+1 << endl;
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
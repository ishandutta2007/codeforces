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
    cin >> n >> a >> b >> c;

    string s;
    cin >> s;

    int st = 0, en = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
            break;
        st++;
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (s[i] == '1')
            break;
        en++;
    }

    if (st == n)
    {
        if (n < 2)
            cout << 0 << endl;
        else
            cout << a << endl;

        return 0;
    }


    //log(ans);

    ll ones = 0;
    ll zersum = max(st-1, 0) + max(en-1, 0);
    vi zeros;
    char cur = '1';
    int curlen = 0;
    for (int i = st; i < n-en; ++i)
    {
        if (s[i] == cur)
            curlen++;
        else
        {
            if (cur == '1')
            {
                ones += curlen-1;
                //log(curlen-1);
            }
            else
            {
                zeros.pb(curlen-1);
                zersum += curlen-1;

            }

            cur = s[i];
            curlen = 1;
        }
    }
        if (cur == '1')
        {
            ones += curlen-1;
            //log(curlen-1);
        }
        else
        {
            zeros.pb(curlen-1);
            zersum += curlen-1;
        }

    //log(ones);
    //log(zersum);

    //log(zeros.size());

    sort(all(zeros));

    //log(ans);

    if (c >= b)
    {
        if (zersum == ones)
        {
            cout << zersum * (a+b) << endl;
            return 0;
        }

        if (zersum > ones)
        {
            cout << ones * (a+b) + a << endl;
            return 0;
        }
        else
        {
            cout << zersum * (a+b) + b << endl;
            return 0;
        }
    }

    int usedones = ones;
    int usedzers = zersum;
    if (zersum >= ones)
        usedzers = ones;
    else
        usedones = usedzers+1;

        //log(usedzers);

    //log(ans);
    ans = 0;
    if (zersum > usedzers)
        ans += a;

    //log(ans);
    ans += usedzers*a;
    ans += usedones*b;
    ll d = b-c;



    //log(zeros.size());

    vi sides;
    if (st > 0)
        sides.pb(st-1);
    if (en > 0)
        sides.pb(en-1);

    sort(all(sides));


    if (ones > zersum + 1 && sides.size() > 0)
        zeros.pb(sides[0]);
    if (ones > zersum + 2 && sides.size() > 1)
        zeros.pb(sides[1]);



    sort(all(zeros));

    //log(zeros.size());

    //log(ans);

    for (int i = 0; i < zeros.size(); ++i)
    {
        //log(i);
        if (zeros[i] <= usedzers)
        {
            ans += d;
            usedzers -= zeros[i];
        }
        else break;
    }

    cout << ans << endl;

    return 0;
}

/*

1
1 2 2 1
0

*/


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
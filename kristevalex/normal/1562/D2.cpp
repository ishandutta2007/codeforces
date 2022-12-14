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


    vi pref;



int GetVal(int l, int r, int before = 0)
{
    int ret = pref[r+1] - pref[l];
    if (l%2 == 1)
        ret = -ret;

    if (before%2 == 1)
        ret = -ret;

    return ret;
}

int solve()
{
    cin >> n >> m;

    vi data(n);
    pref.resize(n+1);

    string vals;
    cin >> vals;
    for (int i = 0; i < n; ++i)
    {
        int vl = i;
        if (vals[i] == '+')
            vl++;
        vl%=2;
        if (vl == 0)
            vl = -1;

        data[i] = vl;
    }

    pref[0] = 0;
    for (int i = 1; i < n+1; ++i)
    {
        pref[i] = pref[i-1] + data[i-1];
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        if (GetVal(l, r) == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if ((r-l+1)%2 == 0)
        {
            cout << 2 << endl << l+1 << " ";
            ++l;
        }
        else
        {
            cout << 1 << endl;
        }

        int low = l-1;
        int high = r;

        int highsign = GetVal(l, r-1);

        if (highsign == 0)
        {
            cout << r+1 << endl;
            continue;
        }

        if (highsign < 0)
            highsign = -1;
        else
            highsign = 1;

        while (high - low > 1)
        {
            int mid = (high + low)/2;
            if ((GetVal(l, mid-1) + GetVal(mid + 1, r, mid - l))*highsign >= 0)
                high = mid;
            else
                low = mid;
        }

        cout << high + 1 << endl;
    }



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
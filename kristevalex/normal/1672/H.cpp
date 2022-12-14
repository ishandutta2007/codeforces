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

string s;

vi pref0, pref1;

int get1(int l, int r)
{
    return pref1[r+1] - pref1[l+1];
}

int get0(int l, int r)
{
    return pref0[r+1] - pref0[l+1];
}

int solve()
{
    int l, r;
    cin >> l >> r;

    --l;
    --r;

    a = get1(l, r);
    b = get0(l, r);

    a = max(a, b);




    cout << a+1 << "\n";

    return 0;
}


int main()
{
    FAST;
    cin >> n;

    int t;
    cin >> t;
    cin >> s;

    pref0.resize(n+1);
    pref1.resize(n+1);
    pref0[0] = 0;
    pref1[0] = 0;
    pref0[1] = 0;
    pref1[1] = 0;

    for (int i = 1; i < n; ++i)
    {
        pref0[i+1] = pref0[i];
        pref1[i+1] = pref1[i];
        if (s[i] == '0' && s[i-1] == '0')
            pref0[i+1]++;
        if (s[i] == '1' && s[i-1] == '1')
            pref1[i+1]++;
    }



    while(t--)
        solve();

    return 0;
}
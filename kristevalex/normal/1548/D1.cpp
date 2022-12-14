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


vector<pii> data;

long long a, b, k, n, m, tmp, ans = 0;

int getpts(pii p1, pii p2)
{
    p1.ft -= p2.ft;
    p1.ft = abs(p1.ft);

    p1.sd -= p2.sd;
    p1.sd = abs(p1.sd);

    return __gcd(p1.ft, p1.sd) - 1;
}



int solve()
{
    cin >> n;

    vl cnt(4, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        a/=2;
        b/=2;
        a%=2;
        b%=2;
        cnt[a+2*b]++;
    }

    for (ll i = 0; i < cnt.size(); ++i)
    {
        //cout << cnt[i] << " " <<  cnt[i]*(cnt[i]-1)/2 << endl;
        ans += (n-cnt[i])*cnt[i]*(cnt[i]-1)/2;
        ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
    }




    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;
        solve();

    return 0;
}
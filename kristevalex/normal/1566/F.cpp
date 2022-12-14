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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << '{'<< x.first << ' ' << x.second << '}';}
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


vl pts;
vl first_end;
vpll segs;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    pts.resize(n);
    segs.resize(m);
    first_end.resize(m);

    cin >> pts;
    cin >> segs;

    sort(all(pts));
    sort(all(segs));

    pts.pb(1e9+6);

    first_end[m-1] = segs[m-1].sd;
    for (int i = m-2; i >= 0; --i)
    {
        first_end[i] = min(first_end[i+1], segs[i].sd);
    }

    vl dp(m+1, 1e15);
    vl tmp(m+1, 1e15);
    dp[0] = 0;

    int cur = 1;
    int prev = 0;
    log(pts);
    log(segs);
    log(first_end);

    for (int id = 0; id < n; ++id)
    {
        ll curpos = pts[id];
        while(cur <= m && segs[cur-1].ft < curpos)
            ++cur;

        ll min1 = dp[cur-1];
        ll min2 = dp[cur-1];

        for (int i = prev; i < cur; ++i)
        {
            ll dst = curpos - first_end[max(i-1, 0)];
            if (dst < 0)
                dst = 0;

            log(curpos);
            log(first_end[max(i-1, 0)]);
            log(i);
            log(dst);
            log(dp[max(i-1, 0)]);

            min1 = min(min1, dp[max(i-1, 0)] + dst);
            min2 = min(min2, dp[max(i-1, 0)] + 2*dst);
            log(min1);
            log(min2);
        }

        ll nextpos = pts[id+1];

        log(cur);
        log(min1);
        log(min2);
        log(dp[cur-1]);

        dp[cur-1] = min(dp[cur-1], min1);

        for (int i = cur; i <= m; ++i)
        {
            if (segs[i-1].ft >= nextpos)
                break;

            ll dst = segs[i-1].ft - curpos;
            if (dst < 0)
                dst = 0;

            dp[i] = min(dp[i], min1 + 2*dst);
            dp[i] = min(dp[i], min2 + dst);
        }

        log(id);
        log(dp);

        prev = cur;
    }





    cout << dp[m] << endl;

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
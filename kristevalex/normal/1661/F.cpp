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
ll cur = 0;


inline ll calc(pii val)
{
    int len = val.ft;
    int pieces = min(val.sd, len);
    //log(len);
    //log(pieces);
    int szmin = len/pieces;
    //log("/");
    int rest = len - szmin*pieces;
    int minnum = pieces - rest;

    return rest * 1ll * (szmin + 1ll) * (szmin + 1ll) + minnum * 1ll * szmin * 1ll * szmin;
}

bool check(ll tot, bool debug = false)
{
    ll ttt = tot;
    priority_queue<pair<ll, pii>> st;

    for (int i = 0; i < n; ++i)
    {
        ll cvl = (::data[i] - 1ll) * (ttt - 1ll) / cur;
        //cvl--;

        cvl = max(cvl, 1ll);

        tot -= cvl - 1;
        //log(i);

        pii part = {::data[i], cvl};
        //log(part.ft);
        //log(part.sd);
        //log(i);
        ll w = calc(part);
        //log(i);
        ll wn = calc({part.ft, part.sd+1});
        st.push({w - wn, part});
    }
    //log("init");

    while (tot--)
    {
        pair<ll, pii> it = st.top();
        st.pop();

        it.sd.sd++;
        ll w = calc(it.sd);
        ll wn = calc({it.sd.ft, it.sd.sd+1});
        it.ft = w - wn;
        st.push(it);
    }

    //log("calc");

    ll sum = 0;
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (debug)
        {
            log(it.sd.ft);
            log(it.sd.sd);
        }
        sum += calc(it.sd);
    }

    return sum <= m;
}

/*

4
1 5 10 12
20

5
1 5 10 19 31
90



*/




int solve()
{
    cin >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ::data[i] = x - cur;
        cur = x;
    }

    cin >> m;

    int l = -1;
    int r = cur - n;

    while (r-l > 1)
    {
        int mid = (l+r)/2;
        //log(l);
        //log(r);
        //log(mid);

        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    //check(r, true);

    cout << r << endl;

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}
#include <set>

struct ConSegs
{
    std::set<std::pair<int, int>> segs;

    void Fill(int l, int r) // [l, r)
    {
        auto itl = segs.lower_bound({l, l-1});
        if (itl == segs.begin())
            itl = segs.end();
        else
        {
            itl--;
            if (itl->second >= l)
            {
                l = std::min(l, itl->first);
                r = std::max(r, itl->second);

                segs.erase(itl);
            }
        }

        auto itp = segs.lower_bound({l, -1});
        while(itp != segs.end())
        {
            auto curid = *itp;
            if (curid.second > r)
            {
                if (curid.first > r)
                    break;

                r = curid.second;
                segs.erase(itp);
                break;
            }

            auto it2 = itp;
            ++itp;
            segs.erase(it2);
        }

        segs.insert({l, r});
    }

    bool IsFilled(int l, int r) // [l, r)
    {
        auto itl = segs.lower_bound({l+1, l-1});
        if (itl == segs.begin())
            return false;
        else
        {
            itl--;
            if (itl->first <= l && itl->second >= r)
                return true;
        }

        return false;
    }

    std::pair<int, int> Get(int x) // [l, r)
    {
        auto itl = segs.lower_bound({x+1, x-1});
        if (itl == segs.begin())
            return {x, x};
        else
        {
            itl--;
            if (itl->first <= x && itl->second > x)
                return *itl;
        }

        return {x, x};
    }
};


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

long long a, b, c, d, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;


    int na = 0;
    int nb = 0;

    n = s.size();

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
            na++;
        else
            nb++;
    }

    if (na-nb != a-b)
    {
        cno;
        //log(1);
        return 0;
    }

    int freesum = 0;
    vi datac;
    vi datad;
    int lockedsum = 0;

    int cur = 0;
    for (int i = 1; i < n; ++i)
    {
        //log(i);
        if (s[i] == s[i-1])
        {
            //log("eq");
            //log(cur);
            if (cur > 0)
            {
                if (cur%2 == 0)
                {
                    freesum += cur/2;
                }
                else
                {
                    if (s[i-1] == 'B')
                        datac.pb((cur+1)/2);
                    else
                        datad.pb((cur+1)/2);
                }
            }
            cur = 0;
        }
        else
            ++cur;
    }
    //log(cur);
    if (cur > 0)
    {
        if (cur%2 == 0)
        {
            freesum += cur/2;
        }
        else
        {
            if (s[n-1] == 'B')
                datac.pb((cur+1)/2);
            else
                datad.pb((cur+1)/2);
        }
    }

    sort(all(datac));
    sort(all(datad));

    for (int i = 0; i < datac.size(); ++i)
    {
        ll cur = datac[i];
        log(0+cur);
        ll cr = min(cur, c);
        cur -= cr;
        c -= cr;
        if (cur > 1 && d > 0)
        {
            d -= cur-1;
        }
    }

    for (int i = 0; i < datad.size(); ++i)
    {
        ll cur = datad[i];
        log(cur+0);
        if (d > 0) {
            ll cr = min(cur, d);
            cur -= cr;
            d -= cr;
        }
        if (cur > 1 && c > 0)
        {
            c -= cur-1;
        }
    }
    c = max(c, 0ll);
    d = max(d, 0ll);
    log(c);
    log(d);
    log(freesum);

    if (c+d > freesum)
    {
        cno;
        return 0;
    }
    cyes;


    /*map<int, int> mp;

    for (int i = 0; i < data.size(); ++i)
    {
        lockedsum+=data[i];
        mp[data[i]]++;
    }

    log("mp");

    if (freesum + lockedsum > c + d)
    {
        cyes;
        log(2);
        return 0;
    }
    if (freesum + lockedsum < c + d)
    {
        cno;
        log(3);
        log(freesum);
        log(lockedsum);
        return 0;
    }

    vector<bool> dp (c+d+2, false);
    int maxx = freesum;
    for (int i = 0; i <= freesum; ++i)
    {
        dp[i] = true;
    }


    //log("dp");

    //log(dp.size());


    /*for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        int key = it->ft;
        int val = it->sd;

        log(key);
        log(val);
        for (int i = maxx; i >= 0; --i)
        {
            for (int j = 1; j <= val; ++j)
            {
                log(i+j*key);
                if (dp[i+j*key] == true)
                    break;
                dp[i+j*key] = true;
            }

        }
        maxx += key*val;
        log(maxx);
    }

    if (dp[c])
    {
        cyes;
    }
    else
    {
        cno;
    }*/





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
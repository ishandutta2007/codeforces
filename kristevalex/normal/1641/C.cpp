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
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;




/*

11 7
0 1 5 0
0 9 11 0
1 8
0 1 11 1
1 8
0 3 7 0
1 8

117 7
0 1 1 1
0 2 5 1
0 2 4 1
0 1 3 1
0 1 5 1
0 9 11 1
0 3 10 1


1117 6
0 1 1 0
0 56 234 0


0 31 41 0
0 11 31 0
0 11 51 0
0 91 111 0

*/


int solve()
{
    cin >> n >> m;

    ::data.assign(n, 2);

    set<int> left;
    for (int i = 0; i < n; ++i)
    {
        left.insert(i);
    }

    set<pii> ones;
    ConSegs segs;

    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            --x;
            int l = x;
            int r = x;
            if (::data[x] == 2)
            {
                auto ll = segs.Get(x-1);
                if (ll.ft != ll.sd)
                    l = ll.ft;
                auto rr = segs.Get(x+1);
                if (rr.ft != rr.sd)
                    r = rr.sd-1;

                /*auto it = segs.lower_bound({x, -1});

                if (it != segs.end())
                {
                    auto val = *it;
                    if (val.ft == x+1)
                        r = val.sd;
                }
                if (it == segs.begin())
                    it = segs.end();
                else
                    --it;

                if (it != segs.end())
                {
                    auto val = *it;
                    if (val.sd == x-1)
                        l = val.ft;
                }*/
                //log(l);
                //log(r);

                auto itr = ones.lower_bound({l, -1});
                if (itr != ones.end())
                {
                    auto val = *itr;
                    if (val.sd <= r)
                    {
                        cout << "YES\n";
                        //cendl;
                        continue;
                    }
                }

                cout << "N/A\n";
                //cendl;
            }
            if (::data[x] == 0)
                cout << "NO\n";
        }
        else
        {
            int l, r;
            cin >> l >> r >> t;


            //log("Hi");
            --l;
            --r;

            if (t == 0)
            {
                auto it = left.lower_bound(l);
                while(it != left.end())
                {
                    int curid = *it;
                    //log(curid);
                    if (curid > r)
                        break;

                    ::data[curid] = 0;

                    auto it2 = it;

                    ++it;

                    left.erase(it2);
                }
                //log("hr");
                /*log(segs.size());
                cout << "zeros" << endl;
    for (auto it = segs.begin(); it != segs.end(); ++it)
    {
        cout << it -> ft << " " << it -> sd << endl;
    }*/

                segs.Fill(l, r+1);
                /*auto itp = segs.lower_bound({l, -1});
                while(itp != segs.end())
                {
                    auto curid = *itp;
                    //log(curid.ft);
                    //log(curid.sd);
                    if (curid.sd > r)
                        break;

                    auto it2 = itp;

                    ++itp;

                    segs.erase(it2);
                }
                //log("24");

                auto itr = segs.lower_bound({l, -1});
                //log("mid");
                auto itl = itr;
                if (itl == segs.begin())
                    itl = segs.end();
                else
                    itl--;

                //log("gh");
                if (itr != segs.end())
                {
                    //log(r);
                    auto curid = *itr;
                    if (curid.ft <= r+1)
                    {
                        r = curid.sd;
                        segs.erase(itr);
                    }
                }

                //log("dfd");
                if (itl != segs.end())
                {
                    auto curid = *itl;
                    if (curid.sd >= l-1)
                    {
                        l = curid.ft;

                        if (curid.sd > r)
                            r = curid.sd;
                        segs.erase(itl);
                    }
                }

                segs.insert({l, r});*/
            }
            else
            {
                //log("hi");
                auto it = ones.lower_bound({l, -1});
                if (it != ones.end())
                {
                    auto curone = *it;
                    if (curone.sd < r)
                        continue;
                }

                //log("mid");

                it = ones.lower_bound({l+1, -1});
                if (it == ones.begin())
                    it = ones.end();
                else
                    --it;



                while (it != ones.end())
                {
                    auto curone = *it;
                    if (curone.sd < r)
                        break;

                    auto it2 = it;

                    if (it == ones.begin())
                        it = ones.end();
                    else
                        --it;

                    ones.erase(it2);
                }

                ones.insert({l, r});
            }
        }
    }


    /*cout << "ones" << endl;
    for (auto it = ones.begin(); it != ones.end(); ++it)
    {
        cout << it -> ft << " " << it -> sd << endl;
    }*/
    /*cout << "zeros" << endl;
    for (auto it = segs.begin(); it != segs.end(); ++it)
    {
        cout << it -> ft << " " << it -> sd << endl;
    }*/




    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
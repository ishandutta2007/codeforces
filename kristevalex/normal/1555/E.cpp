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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ft first
#define sd second


vector<pair<ll, pll>> data;

long long a, b, k, n, m, tmp, ans = 1e17;


const int MAXN = 2e6;


long long t[2*MAXN];
long long td[2*MAXN] = {};

void build (int v, int tl, int tr)
    {
    if (tl == tr)
        {
        t[v] = 0;
        }
    else
        {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);

        t[v] = min(t[2*v], t[2*v+1]);
        td[v] = 0;
        }
    }

void build_ ()
    {
    build (1, 0, m-1);
    }


long long query (int v, int tl, int tr, int l, int r)
    {
    if (l > r)
        return 10000000000;
    if (l == tl && tr == r)
        {
           // cout << "val ["<<l <<", "<<r<<"] td:" << td[v] << ", t:" << t[v] <<endl;
        return t[v] + td[v];
        }
    int tm = (tl + tr) / 2;

    td[v*2] += td[v];
    td[v*2 +1] += td[v];
    td[v] = 0;

    long long lf = query (v*2, tl, tm, l, min(r,tm));
    long long ri = query (v*2+1, tm+1, tr, max(l,tm+1), r);


    t[v] = min(lf, ri);

    //cout << "val ["<<l <<", "<<r<<"] td:" << td[v] << ", t:" << t[v] <<endl;


    return t[v] + td[v];
    }

long long query_(int l, int r)
    {
    return query(1, 0, m-1, l, r);
    }

void update (int v, int tl, int tr, int l, int r, int diff)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        td[v] += diff;

        //cout << "for ["<<tl <<", "<<tr<<"] td:" << td[v] << ", t:" << t[v] <<endl;

        return;
    }

    int tm = (tl + tr) / 2;

    td[v*2] += td[v];
    td[v*2 +1] += td[v];
    td[v] = 0;

    update(v*2, tl, tm, l, min(r,tm), diff);
    update(v*2+1, tm+1, tr, max(l,tm+1), r, diff);

    t[v] = min(t[2*v] + td[2*v], t[2*v+1] + td[2*v+1]);
    //cout << "for ["<<tl <<", "<<tr<<"] td:" << td[v] << ", t:" << t[v] <<endl;
}

void update_ (int l, int r, int diff)
    {
    update (1, 0, m-1, l, r, diff);
    }


int solve()
{
    cin >> n >> m;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i].sd.ft >> ::data[i].sd.sd >> ::data[i].ft;
        ::data[i].sd.ft--;
        ::data[i].sd.sd--;
    }


    build_();
    sort(all(::data));
    int r = -1;

    for (int l = 0; r < n; ++l)
    {
        while(query_(0, m-2) == 0)
        {
            ++r;
            if (r >= n) break;
            update_(::data[r].sd.ft, ::data[r].sd.sd-1, 1);
            //cout << "+l:"<<::data[r].sd.ft <<", r:"<<::data[r].sd.sd-1<<endl;
        }
        if (r >= n) break;
        ans = min(ans, ::data[r].ft - ::data[l].ft);
            //cout << "l:"<<l <<", r:"<<r<<endl;

        update_(::data[l].sd.ft, ::data[l].sd.sd-1, -1);
    }




    cout << ans;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
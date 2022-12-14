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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
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
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<vector<pii>> dt;
vvi g;
vector<bool> used;

long long a, b, k, n, m, tmp, ans = 0;

void dfs(int cur, int prev = -1)
{
    //log(cur);
    //log(prev);
    if (prev != -1)
        dt[dt.size()-1].pb({cur, prev});
    if (used[cur])
        return;
    used[cur] = true;
    int i = 0;
    if (prev == -1)
        prev = g[cur][1];
    for ( ; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;
        //cout << "next("<<next<<") for " << cur << endl;

        dfs(next, cur);
    }
}

void print()
{
    cout << "sz: " << dt.size() << endl;
    cout << "{\n";

    for (int id = 0; id < dt.size(); ++id)
    {
        cout << "  id: " <<id << endl;
        cout << "  {\n";

        for (int i = 0; i < dt[id].size(); ++i)
        {
            cout << "    " << dt[id][i]<<endl;
        }

        cout << "  }\n" << endl;
    }

    cout << "}\n" << endl;
}

ll has(int hasL, int hasH, int hasL2 = -1, int hasH2 = -1, int Lban = -1, int Hban = -1)
{
    int Llow = -1;
    int Lhigh = n;
    int Hlow = n-1;
    int Hhigh = 2*n;

    bool scd = hasH2 != -1;

    if (false)
    {
        log(hasL);
        log(hasL2);
        log(hasH);
        log(hasH2);
        log(Llow);
        log(Lhigh);
        log(Hlow);
        log(Hhigh);
        cendl;
    }

    if (hasH2 == -1)
        hasH2 = hasH;
    if (hasL2 == -1)
        hasL2 = hasL;

    if (hasH > hasH2)
        swap(hasH, hasH2);
    if (hasL > hasL2)
        swap(hasL, hasL2);

    if (Llow > Lhigh)
        swap(Llow, Lhigh);
    if (Hlow > Hhigh)
        swap(Hlow, Hhigh);

    if (false)
    {
        log(hasL);
        log(hasL2);
        log(hasH);
        log(hasH2);
        log(Llow);
        log(Lhigh);
        log(Hlow);
        log(Hhigh);
        cendl;
    }

    scd = scd && (false);

    if (Hban != -1)
    {
        if (Hban < hasH)
            Hlow = Hban;
        else
            Hhigh = Hban;

        if (Lban < hasL)
            Llow = Lban;
        else
            Lhigh = Lban;
    }

    /*if (scd)
    {
        log(hasL);
        log(hasH);
        log(Llow);
        log(Lhigh);
        log(Hlow);
        log(Hhigh);
        log(1ll*(hasL-Llow)*(Lhigh-hasL2)*(hasH-Hlow)*(Hhigh-hasH2));
        cendl;
    }*/

    if (hasL <= Llow || hasL2 >= Lhigh)
        return 0;
    if (hasH <= Hlow || hasH2 >= Hhigh)
        return 0;

    /*if (scd)
    {
        log(hasL);
        log(hasH);
        log(1ll*(hasL-Llow)*(Lhigh-hasL2)*(hasH-Hlow)*(Hhigh-hasH2));
    }*/

    return 1ll*(hasL-Llow)*(Lhigh-hasL2)*(hasH-Hlow)*(Hhigh-hasH2);
}

/*

2
1 3
1 4
2 3
2 4

1-2 3-4
2
1-1 3-4
2-2 3-4
1-2 3-3
1-2 4-4
1-1 3-3
1-1 4-4
2-2 3-3
2-2 4-4

3
1 4
1 6
2 4
2 5
3 5
3 6



*/

int solve()
{
    cin >> n;

    g.resize(2*n);
    used.assign(2*n, false);

    for (int i = 0; i < 2*n; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].pb(u);
        g[u].pb(v);
    }

    for (int i = 0; i < n; ++i)
    {
        if (used[i])
            continue;

        dt.pb(vpii());
        dfs(i);
    }

    //print();

    for (int id = 0; id < dt.size(); ++id)
    {
        for (int i = 0; i < dt[id].size(); i += 2)
        {
            swap(dt[id][i].ft, dt[id][i].sd);
        }
        for (int i = 0; i < dt[id].size(); i += 2)
        {
            ll cfull = has(dt[id][i].ft, dt[id][i].sd);
            //log(cfull);
            //cendl;
            ans += cfull;
        }

        for (int i = 2; i <= dt[id].size(); i += 2)
        {
            int Lmin = dt[id][i-1].ft;
            int Lmax = dt[id][i-1].ft;
            int Hmin = dt[id][i-1].sd;
            int Hmax = dt[id][i-1].sd;

            //log(i);
            for (int j = 0; j < dt[id].size(); j += 2)
            {
                int i1 = (i+j)%dt[id].size();
                int i2 = (i+j+1)%dt[id].size();

                //if (j!=0)continue;

                //log(dt[id][i-2]);
                //log(dt[id][i-1]);
                //log(dt[id][i1]);
                //log(j);
                //cout << "hasL: " << Lmin << " " << Lmax << endl;
                //cout << "hasH: " << Hmin << " " << Hmax << endl;
                //cout << "ban1: " << dt[id][i-2].ft << ' ' << dt[id][i1].sd << endl;

                ll cr = has(Lmin, Hmin, Lmax, Hmax, dt[id][i-2].ft, dt[id][i1].sd);
                ans += cr;

                //log(cr);
                //cendl;


                Lmin = min(Lmin, dt[id][i1].ft);
                Lmax = max(Lmax, dt[id][i1].ft);
                Hmin = min(Hmin, dt[id][i1].sd);
                Hmax = max(Hmax, dt[id][i1].sd);

                Lmin = min(Lmin, dt[id][i2].ft);
                Lmax = max(Lmax, dt[id][i2].ft);
                Hmin = min(Hmin, dt[id][i2].sd);
                Hmax = max(Hmax, dt[id][i2].sd);
            }
        }
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
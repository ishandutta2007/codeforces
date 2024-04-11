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


vector<string> data;

vvi depth;
vvi as;

long long a, b, k, n, m, tmp, ans = 0;


vpii curseq;

int fill1(pii pos, int vl)
{
    while (true)
    {
        if (pos.ft < 0 || pos.ft >= n || pos.sd < 0 || pos.sd >= m)
            break;

        if (as[pos.ft][pos.sd] != -1)
            break;

        as[pos.ft][pos.sd] = vl;

        pii nextpos = pos;

        if (::data[pos.ft][pos.sd] == 'L') nextpos.sd--;
        if (::data[pos.ft][pos.sd] == 'R') nextpos.sd++;
        if (::data[pos.ft][pos.sd] == 'U') nextpos.ft--;
        if (::data[pos.ft][pos.sd] == 'D') nextpos.ft++;

        pos = nextpos;
    }
}

int dfs2(pii pos, int vl)
{
    if (pos.ft < 0 || pos.ft >= n || pos.sd < 0 || pos.sd >= m)
        return 0;

    if (as[pos.ft][pos.sd] != -1)
        return 0;

    as[pos.ft][pos.sd] = vl;


    pii nextpos = pos;

    if (::data[pos.ft][pos.sd] == 'L') nextpos.sd--;
    if (::data[pos.ft][pos.sd] == 'R') nextpos.sd++;
    if (::data[pos.ft][pos.sd] == 'U') nextpos.ft--;
    if (::data[pos.ft][pos.sd] == 'D') nextpos.ft++;

    dfs2(nextpos, vl);
}

int run(pii pos)
{
    curseq.resize(0);
    int d = 1;
    while(true)
    {
        if (pos.ft < 0 || pos.ft >= n || pos.sd < 0 || pos.sd >= m)
            break;

        curseq.pb(pos);

        if (as[pos.ft][pos.sd] != -1)
            break;

        if (depth[pos.ft][pos.sd] != -1)
        {
            fill1(pos, d - depth[pos.ft][pos.sd]);
            break;
        }



        pii nextpos = pos;
        depth[pos.ft][pos.sd] = d;

        if (::data[pos.ft][pos.sd] == 'L') nextpos.sd--;
        if (::data[pos.ft][pos.sd] == 'R') nextpos.sd++;
        if (::data[pos.ft][pos.sd] == 'U') nextpos.ft--;
        if (::data[pos.ft][pos.sd] == 'D') nextpos.ft++;

        pos = nextpos;



        ++d;
    }


    for (int i = curseq.size() - 1; i >= 0; --i)
    {
        pii cur  = curseq[i];

        if (as[cur.ft][cur.sd] != -1)
            continue;

        if (i == curseq.size() - 1)
            as[cur.ft][cur.sd] = 1;
        else
            as[cur.ft][cur.sd] = as[curseq[i+1].ft][curseq[i+1].sd]+1;
    }
}

int dfs(pii pos, int d)
{
    if (pos.ft < 0 || pos.ft >= n || pos.sd < 0 || pos.sd >= m)
        return 0;

    if (as[pos.ft][pos.sd] != -1)
        return as[pos.ft][pos.sd];

    if (depth[pos.ft][pos.sd] != -1)
    {
        dfs2(pos, d - depth[pos.ft][pos.sd]);
        return as[pos.ft][pos.sd];
    }

    pii nextpos = pos;
    depth[pos.ft][pos.sd] = d;

    if (::data[pos.ft][pos.sd] == 'L') nextpos.sd--;
    if (::data[pos.ft][pos.sd] == 'R') nextpos.sd++;
    if (::data[pos.ft][pos.sd] == 'U') nextpos.ft--;
    if (::data[pos.ft][pos.sd] == 'D') nextpos.ft++;

    int next = dfs(nextpos, d+1);

    //cout << "next: " << next << endl;

    if (as[pos.ft][pos.sd] == -1)
        {as[pos.ft][pos.sd] = next+1;/*cout << "hi " << pos.ft << " " << pos.sd  << " "<<as[pos.ft][pos.sd] << endl;*/}


    return as[pos.ft][pos.sd];
}


int solve()
{
    cin >> n >> m;

    ::data.resize(n);
    ::depth.assign(n, vi(m, -1));
    ::as.assign(n, vi(m, -1));

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];



    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (as[i][j] == -1)
            run({i, j});
        }
    }

    int maxx = -1;
    int maxi;
    int maxj;



    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            //cout << as[i][j] << " ";
            if (as[i][j] > maxx)
            {
                maxi = i+1;
                maxj = j+1;
                maxx = as[i][j];
            }
        }
        //cendl;
    }


    cout << maxi << " " << maxj << " " << maxx << endl;

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
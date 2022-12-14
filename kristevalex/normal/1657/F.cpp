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

#include <vector>

int l, sz;
std::vector<std::vector<int>> g;
std::vector<int> tin, tout;
int timer;
std::vector<std::vector<int>> up;
vi dists;

void dfs_lca (int v = 0, int p = 0, int dst = 0)
{
    dists[v] = dst;
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];

	for (size_t i = 0; i < g[v].size(); ++i)
    {
		int to = g[v][i];
		if (to != p)
			dfs_lca (to, v, dst+1);
	}

	tout[v] = ++timer;
}

bool upper (int v1, int v2)
{
	return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}


int lca (int v1, int v2)
{
	if (upper (v1, v2))  return v1;
	if (upper (v2, v1))  return v2;
	for (int i = l; i >= 0; --i)
		if (!upper (up[v1][i], v2))
			v1 = up[v1][i];
	return up[v1][0];
}

void SetupLCA()
{
    sz = g.size();
    dists.resize(sz);
    tin.resize(sz);
    tout.resize(sz);
    up.resize(sz);
	l = 1;
	timer = 0;
	while ((1<<l) <= sz)
        ++l;
	for (int i = 0; i < sz; ++i)
        up[i].resize(l+1);
	dfs_lca(0);
}


vector<pair<char, char>> possible;
vector<pair<string, pii>> queries;
vvi updates;

stack<int> vupd;

int n;
bool failed = false;
string s;
int fillcnt = -1;

bool Fill(int, int, bool);


void print()
{
    for (int i = 0; i < n; ++i)
    {
        cout << "vertex " << i << ": ";

        if (possible[i].ft == possible[i].sd)
            cout << possible[i].ft << endl;
        else
            cout << possible[i].ft << " " << possible[i].sd << endl;
    }
}

pair<char, char> eq(pair<char, char> v1, pair<char, char> v2)
{
    if (v1.ft == '#')
        return v2;
    if (v2.ft == '#')
        return v1;


    if (v1.ft < v1.sd)
        swap(v1.ft, v1.sd);
    if (v2.ft < v2.sd)
        swap(v2.ft, v2.sd);

    if (v1.ft == v2.ft && v1.sd == v2.sd)
        return v1;

    if (v1.ft == v2.ft)
        return {v1.ft, v1.ft};
    if (v1.ft == v2.sd)
        return {v1.ft, v1.ft};
    if (v1.sd == v2.ft)
        return {v1.sd, v1.sd};
    if (v1.sd == v2.sd)
        return {v1.sd, v1.sd};

    return {'!', '!'};
}

int dist (int u, int v)
{
    int lcauv = lca(u, v);
    return dists[u] + dists[v] - 2*dists[lcauv];
}

inline bool UpdLine(int v, int id)
{
    int v1 = queries[id].sd.ft;
    int v2 = queries[id].sd.sd;
    string str = queries[id].ft;
    int dst = dist(v1, v);
    if (str[dst] != possible[v].ft)
        reverse(all(str));

    int lc = lca(v1, v2);

    s = str;
    if (!Fill(v1, lc, false))
        return false;

    reverse(all(s));

    return Fill(v2, lc, false);
}

inline bool Upd(int v)
{
    for (int i = 0; i < updates[v].size(); ++i)
    {
        int id = updates[v][i];
        //log("upd");
        //log(id);
        //log(queries[id].ft);
        if (queries[id].ft == "##")
        {
            //log("upd ##");
            continue;
        }

        if (!UpdLine(v, id))
            return false;
        //log(id);
        //log("upd");

        queries[id].ft = "##";
    }

    updates[v] = vi();
    return true;
}

inline bool UpdAll()
{
    while(!vupd.empty())
    {
        //log("updall");
        int cur = vupd.top();
        //log(cur);
        vupd.pop();
        if (!Upd(cur))
        {
            //cout << "failed on cur == " << cur << endl;
            return false;
        }
        //log(cur);
        //log("updall");
    }

    return true;
}

bool Fill(int v, int root, bool doupdate = true)
{
    //cout << "Fill v[" << v << "] root[" << root << "] ";
    //if (!doupdate)
    //    cout << "from_upd ";
    //    cout << "from_upd v[" << v << "] root[" << root << "]" << endl;;
    if (doupdate)
        ++fillcnt;
    //cout << "fillcnt[" << fillcnt << "]" << endl;

    int len = 0;
    while(true)
    {
        //cendl;
        //log(v);
        char c1 = s[len];
        char c2 = s[s.size()-len-1];
        if (!doupdate)
        {
            c2 = c1;
            //cout << "updating v[" << v << "] : " << c1 << "/" << c2 << endl;
        }
        //log(c1);
        //log(c2);
        //log(s);
        //log(len);

        auto mrg = eq({c1, c2}, possible[v]);
        //log(mrg.ft);
        //log(mrg.sd);
        if (mrg.ft == '!')
            return false;

        possible[v] = mrg;

        if (mrg.ft == mrg.sd)
        {
            //log("vupd");
            //log(v);
            vupd.push(v);
        }
        if (c1 != c2 && doupdate)
            updates[v].pb(fillcnt);

        if (v == root)
            break;
        ++len;
        v = up[v][0];
    }

    if (!doupdate)
        return true;

    //log("end fill");
    //print();

    return UpdAll();
}

/*

2 1
1 2
1 2 ab

7 2
1 2
6 1
2 3
3 5
4 3
7 3
2 7 ded
6 4 edeg

5 2
1 2
2 3
2 4
2 5
3 5 dbf
2 1 fb

7 5
1 2
2 3
3 4
4 5
5 6
6 7
2 3 ba
3 4 bc
5 4 dc
5 6 de
5 7 fed

5 3
3 4
3 2
4 1
4 5
2 4 bac
4 2 cab
5 1 dba


*/

int solve()
{
    int q;
    cin >> n >> q;

    possible.assign(n, {'#', '#'});
    g.resize(n);
    updates.resize(n);
    queries.resize(q);
    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    SetupLCA();


    for (int id = 0; id < q; ++id)
    {
        //cendl;
        int u, v;
        cin >> u >> v >> s;
        string tmp = s;
        --u;
        --v;
        queries[id] = {s, {u, v}};

        if (failed)
            continue;

        int uv = lca(u, v);
        //log("lca");

        if (!Fill(u, uv))
        {
            //log("fails");
            failed = true;
            continue;
        }
        //log("oks");
        s = tmp;
        reverse(all(s));
        --fillcnt;

        //cendl;
        if (!Fill(v, uv))
        {
            //log("fails2");
            failed = true;
            //print();
            continue;
        }
        //log("oks2");
        //print();

    }

    if (failed)
    {
        cno;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (possible[i].ft == possible[i].sd && possible[i].ft != '#')
            continue;

        s = "1";
        s[0] = possible[i].ft;
        if (s[0] == '#')
            s[0] = 'a';
        //log(s);
        //log(i);
        //log("endfill");
        Fill(i, i);
        //log("endfill");
        //log(i);
    }

    cyes;
    for (int i = 0; i < n; ++i)
        cout << possible[i].ft;
    cendl;



    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}
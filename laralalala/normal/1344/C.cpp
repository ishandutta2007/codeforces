#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> scc_gabow(graph &adj)
{
	int n = adj.n;

	vector<vector<int>> scc;
	vector<int> S, B, I(n);

	function<void(int)> dfs = [&](int u)
	{
		B.push_back(I[u] = S.size());
		S.push_back(u);

		for (int v : adj[u])
			if (!I[v]) dfs(v);
			else while (I[v] < B.back()) B.pop_back();

		if (I[u] == B.back())
		{
			scc.push_back({});
			for (B.pop_back(); I[u] < S.size(); S.pop_back())
			{
				scc.back().push_back(S.back());
				I[S.back()] = n + scc.size();
			}
		}
	};

	for (int u = 0; u < n; ++u)
		if (!I[u]) dfs(u);

	return scc;
}
#define MAXN 200005

vector<int> gg[MAXN],ig[MAXN];
int res[MAXN],mkg[MAXN],mki[MAXN];

void dfsg(int u)
{
    for(auto v : gg[u])
    {
        if(!mkg[v])
        {
            res[v]=1;
            mkg[v]=1;
            dfsg(v);
        }
    }
}

void dfsi(int u)
{
    for(auto v : ig[u])
    {
        if(!mki[v])
        {
            res[v]=1;
            mki[v]=1;
            dfsi(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    graph g(n);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g.add_edge(u,v);
        gg[u].push_back(v);
        ig[v].push_back(u);
    }

    vector<vector<int> > scc=scc_gabow(g);

    bool ok=1;
    for(auto y : scc)
        ok&=(y.size()==1);
    if(!ok)
    {
        db(-1)
        return 0;
    }
    for(int i=0;i<n;i++)
        res[i]=-1;
    int r1=0;
    for(int i=0;i<n;i++)
    {
        if(res[i]==-1)
        {
            res[i]=0;
            r1++;
        }
        mkg[i]=1;
        dfsg(i);
        mki[i]=1;
        dfsi(i);
    }

    db(r1)
    for(int i=0;i<n;i++)
    {
        if(!res[i])
            cout << 'A';
        else
            cout << 'E';
    }
    cout << '\n';

    return 0;
}
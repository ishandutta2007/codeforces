#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

template<typename T>
struct dinic
{
	struct edge
	{
		int src, dst;
		T low, cap, flow;
		int rev;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n + 2) {}

	void add_edge(int src, int dst, T low, T cap)
	{
		adj[src].push_back({ src, dst, low, cap, 0, (int) adj[dst].size() });
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, 0, (int) adj[src].size() - 1 });
	}

	vector<int> level, iter;

	T augment(int u, int t, T cur)
	{
		if (u == t)
			return cur;
		for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
		{
			edge &e = adj[u][i];
			if (e.cap - e.flow > 0 && level[u] > level[e.dst])
			{
				T f = augment(e.dst, t, min(cur, e.cap - e.flow));
				if (f > 0)
				{
					e.flow += f;
					adj[e.dst][e.rev].flow -= f;
					return f;
				}
			}
		}
		return 0;
	}

	int bfs(int s, int t)
	{
		level.assign(n + 2, n + 2);
		level[t] = 0;
		queue<int> Q;
		for (Q.push(t); !Q.empty(); Q.pop())
		{
			int u = Q.front();
			if (u == s)
				break;
			for (edge &e : adj[u])
			{
				edge &erev = adj[e.dst][e.rev];
				if (erev.cap - erev.flow > 0
					&& level[e.dst] > level[u] + 1)
				{
					Q.push(e.dst);
					level[e.dst] = level[u] + 1;
				}
			}
		}
		return level[s];
	}

	const T oo = numeric_limits<T>::max();

	T max_flow(int source, int sink)
	{
		vector<T> delta(n + 2);

		for (int u = 0; u < n; ++u) // initialize
			for (auto &e : adj[u])
			{
				delta[e.src] -= e.low;
				delta[e.dst] += e.low;
				e.cap -= e.low;
				e.flow = 0;
			}

		T sum = 0;
		int s = n, t = n + 1;

		for (int u = 0; u < n; ++u)
		{
			if (delta[u] > 0)
			{
				add_edge(s, u, 0, delta[u]);
				sum += delta[u];
			}
			else if (delta[u] < 0)
				add_edge(u, t, 0, -delta[u]);
		}

		add_edge(sink, source, 0, oo);
		T flow = 0;

		while (bfs(s, t) < n + 2)
		{
			iter.assign(n + 2, 0);
			for (T f; (f = augment(s, t, oo)) > 0;)
				flow += f;
		}

		if (flow != sum)
			return -1; // no solution

		for (int u = 0; u < n; ++u)
			for (auto &e : adj[u])
			{
				e.cap += e.low;
				e.flow += e.low;
				edge &erev = adj[e.dst][e.rev];
				erev.cap -= e.low;
				erev.flow -= e.low;
			}

		adj[sink].pop_back();
		adj[source].pop_back();

		while (bfs(source, sink) < n + 2)
		{
			iter.assign(n + 2, 0);
			for (T f; (f = augment(source, sink, oo)) > 0;)
				flow += f;
		} // level[u] == n + 2 ==> s-side

		return flow;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    ll r,b;
    cin >> r >> b;
    bool sw=0;
    if(r>b)
    {
        swap(r,b);
        sw=1;
    }

    vector<pii> ps;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        ps.push_back(pii(x,y));
    }

    map<int,int> mx;
    map<int,int> my;
    for(int i=0;i<m;i++)
    {
        int t,l,d;
        cin >> t >> l >> d;
        if(t==1)
        {
            int v=mx[l];
            if(!v)
                mx[l]=d+1;
            else
                mx[l]=min(d+1,v);
        }
        else
        {
            int v=my[l];
            if(!v)
                my[l]=d+1;
            else
                my[l]=min(d+1,v);
        }
    }

    int cont=1;
    map<int,int> tx;
    vector<int> itx;
    for(auto p : mx)
    {
        tx[p.f]=cont;
        itx.push_back(p.f);
        cont++;
    }
    vector<int> fx(cont-1);

    cont=1;
    map<int,int> ty;
    vector<int> ity;
    for(auto p : my)
    {
        ty[p.f]=cont;
        ity.push_back(p.f);
        cont++;
    }
    vector<int> fy(cont-1);

    map<int,int> totx,toty;

    dinic<int> g(2+mx.size()+my.size());
    int s=0;
    int t=1+mx.size()+my.size();
    for(int i=0;i<n;i++)
    {
        totx[ps[i].f]++;
        toty[ps[i].s]++;
        if(mx[ps[i].f] && my[ps[i].s])
        {
//            cout << tx[ps[i].f] << ' ' << mx.size()+ty[ps[i].s] << '\n';
            g.add_edge(tx[ps[i].f],fx.size()+ty[ps[i].s],0,1);
            fx[tx[ps[i].f]-1]++;
            fy[ty[ps[i].s]-1]++;
        }
    }
//    db(fx.size())
//    db(fy.size())
//    db("")
    for(int i=0;i<fx.size();i++)
    {
        int tot=totx[itx[i]];
        g.add_edge(i+1,t,0,tot-fx[i]);
        int dif=mx[itx[i]]-1;
        if(dif<0)
        {
            g.add_edge(s,i+1,0,tot);
            continue;
        }
        if((dif&1)!=(tot&1))
            dif--;
        if(dif<0)
        {
            db("-1")
            return 0;
        }
        dif=min(dif,tot);
        int cap=(tot-dif)/2;
//        db(i)
//        cout << tx[itx[i]] << ' ' << cap << ' ' << tot-cap << '\n';
        g.add_edge(s,i+1,cap,tot-cap);
    }

//    db("")
    for(int i=0;i<fy.size();i++)
    {
        int tot=toty[ity[i]];
        g.add_edge(s,fx.size()+i+1,0,tot-fy[i]);
        int dif=my[ity[i]]-1;
        if(dif<0)
        {
            g.add_edge(fx.size()+i+1,t,0,tot);
            continue;
        }
        if((dif&1)!=(tot&1))
            dif--;
        if(dif<0)
        {
            db("-1")
            return 0;
        }
        dif=min(dif,tot);
        int cap=(tot-dif)/2;
//        db(i)
//        cout << tx[itx[i]] << ' ' << cap << ' ' << tot-cap << '\n';
        g.add_edge(fx.size()+i+1,t,cap,tot-cap);
    }

    int x=g.max_flow(s,t);

//    db("xxx")
//    db(x)
    if(x==-1)
    {
        db(-1)
        return 0;
    }

//    db(x)
    map<pii,int> f;
    for(int i=1;i<=fx.size();i++)
    {
//        db("")
//        db(i)
        for(auto e : g.adj[i])
            if(e.dst>fx.size() && e.dst<=fx.size()+fy.size() && e.flow)
            {
                int x=itx[i-1];
                int y=ity[e.dst-fx.size()-1];
                f[pii(x,y)]++;
            }
//            cout << e.src << ' ' << e.dst << ' ' << e.low << ' ' << e.cap << ' ' << e.flow << '\n';
//        db("")
    }

    vector<bool> mk1(n);
    vector<bool> c(n);
    vector<int> actx(fx.size());
    vector<int> acty(fy.size());
    vector<int> lx(fx.size());
    vector<int> ly(fy.size());
    for(int i=0;i<n;i++)
    {
        int x=ps[i].f;
        int y=ps[i].s;
        if(mx[x] && my[y])
        {
            mk1[i]=1;
            if(f[pii(x,y)])
            {
                c[i]=1;
                f[pii(x,y)]--;
                actx[tx[x]-1]++;
                acty[ty[y]-1]++;
            }
        }
    }

//    db("xxx")
    for(int i=0;i<fx.size();i++)
    {
//        db(i)
        int tot=totx[itx[i]];
        int dif=mx[itx[i]]-1;
        if(dif==-1)
        {
            lx[i]=tot;
            continue;
        }
        if((dif&1)!=(tot&1))
            dif--;
        if(dif<0)
        {
            db("-1")
            return 0;
        }
        dif=min(dif,tot);
        int cap=(tot-dif)/2;
        lx[i]=tot-cap;
    }

    for(int i=0;i<fy.size();i++)
    {
//        db(i)
        int tot=toty[ity[i]];
        int dif=my[ity[i]]-1;
        if(dif==-1)
        {
            ly[i]=tot;
            continue;
        }
        if((dif&1)!=(tot&1))
            dif--;
        if(dif<0)
        {
            db("-1")
            return 0;
        }
        dif=min(dif,tot);
        int cap=(tot-dif)/2;
        ly[i]=tot-cap;
    }
//    db("xxx")

    vector<int> fin(n);
    for(int i=0;i<n;i++)
    {
        int x=ps[i].f;
        int y=ps[i].s;
        if(mk1[i])
            continue;
        if(mx[x])
        {
            int px=tx[x]-1;
            if(actx[px]<lx[px])
            {
                c[i]=1;
                actx[px]++;
            }
        }
        else if(my[y])
        {
            int py=ty[y]-1;
            if(acty[py]<ly[py])
            {
                c[i]=1;
                acty[py]++;
            }
        }
        else
            c[i]=1;
    }

    ll av=0;
    string ans(n,'j');
    vector<int> vals={b,r};
    for(int i=0;i<n;i++)
    {
        ans[i]="br"[c[i]^sw];
        av+=vals[c[i]];
    }
    db(av)
    db(ans)

    return 0;
}
/**
5 6
8 3
2 10
1 5
9 10
9 10
2 8
1 9 1
1 2 1
2 10 3
2 10 2
1 1 1
2 5 2
**/
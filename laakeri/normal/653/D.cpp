#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-11;

struct MaxFlow {
	// Use vector<map<int, ll> > for sparse graphs
	vector<vector<ll> > f;
	vector<vector<int> > g;
	vector<int> used;
	int cc;

	ll flow(int x, int t, ll fl, ll miv) {
		if (x==t) return fl;
		used[x]=cc;
		for (int nx:g[x]) {
			if (used[nx]!=cc&&f[x][nx]>=miv) {
				ll r=flow(nx, t, min(fl, f[x][nx]), miv);
				if (r>0) {
					f[x][nx]-=r;
					f[nx][x]+=r;
					return r;
				}
			}
		}
		return 0;
	}

	// maxv is maximum expected maxflow
	ll getMaxFlow(int source, int sink, ll maxv) {
		cc=1;
		ll r=0;
		ll k=1;
		while (k*2<=maxv) k*=2;
		for (;k>0;k/=2) {
			while (ll t=flow(source, sink, maxv, k)) {
				r+=t;
				cc++;
			}
			cc++;
		}
		return r;
	}

	void addEdge(int a, int b, ll c) {
		if (f[a][b]==0&&f[b][a]==0) {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		f[a][b]+=c;
	}

	MaxFlow(int n) : f(n+1), g(n+1), used(n+1) {
		for (int i=1;i<=n;i++) {
			f[i]=vector<ll>(n+1);
		}
	}
};

vector<pair<pair<int, int>, int> > es;

int n,m,x;

int test(ld w){
    MaxFlow mf(n);
    for (auto e:es){
        mf.addEdge(e.F.F, e.F.S, min((ll)floor((ld)e.S/w+eps), (ll)x));
    }
    int f=mf.getMaxFlow(1, n, x);
    if (f>=x) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        es.push_back({{a, b}, c});
    }
    ld mi=0;
    ld ma=1000001;
    for (int t=0;t<60;t++){
        ld mid=(mi+ma)/(ld)2;
        if (test(mid)){
            mi=mid;
        }
        else{
            ma=mid;
        }
    }
    cout<<setprecision(15)<<mi*(ld)x<<endl;
}
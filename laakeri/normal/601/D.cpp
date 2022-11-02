#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll k1=59;
const ll k2=37;

ll pot(ll x, ll p, ll mod){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2, mod);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1, mod))%mod;
}

ll inv(ll x, ll mod){
	return pot(x, mod-2, mod);
}

void add(pair<ll, ll>&h, char c) {
	h.F*=k1;
	h.S*=k2;
	h.F+=(ll)c;
	h.S+=(ll)c;
	h.F%=mod1;
	h.S%=mod2;
}

set<pair<ll, ll> > hs[303030];
pair<ll, ll> th[303030];
ll c[303030];
vector<int> g[303030];

string s;

void dfs(int x, int p, pair<ll, ll> h){
	add(h, s[x-1]);
	th[x]=h;
	for (int nx:g[x]){
		if (nx!=p){
			dfs(nx, x, h);
		}
	}
}

ll vv[303030];

ll mv=0;

int dfs2(int x, int p){
	if ((int)g[x].size()==1&&p!=0){
		vv[x]=1;
		hs[x].insert(th[x]);
		mv=max(mv, vv[x]+c[x]);
		return x;
	}
	vector<pair<int, int> > lol;
	for (int nx:g[x]){
		if (nx!=p){
			int k=dfs2(nx, x);
			lol.push_back({(int)hs[k].size(), k});
		}
	}
	sort(lol.rbegin(), lol.rend());
	int tk=lol[0].S;
	for (int i=1;i<(int)lol.size();i++){
		for (auto h:hs[lol[i].S]){
			hs[tk].insert(h);
		}
	}
	hs[tk].insert(th[x]);
	vv[x]=(int)hs[tk].size();
	mv=max(mv, vv[x]+c[x]);
	//cout<<x<<" "<<vv[x]<<" "<<c[x]<<endl;
	return tk;
}

int vvv=0;

void dfs3(int x, int p){
	if (vv[x]+c[x]==mv){
		vvv++;
	}
	for (int nx:g[x]){
		if (nx!=p){
			dfs3(nx, x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	cin>>s;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (n==1){
		cout<<1+c[1]<<endl<<1<<endl;
		return 0;
	}
	dfs(1, 0, {0, 0});
	dfs2(1, 0);
	cout<<mv<<endl;
	dfs3(1, 0);
	cout<<vvv<<endl;
}
#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,s,t;

vector<pair<int, int> > g[1010];
ll w[10101];
int a[10101];
int b[10101];
int u1[1010];
ll di1[1010];
int u2[1010];
ll di2[1010];

int is(int id, ll d){
	if (u1[a[id]]&&u1[b[id]]){
		if (di1[a[id]]<di1[b[id]]){
			if (di1[a[id]]+w[id]+di2[b[id]]==d) return 1;
			else return 0;
		}
		else{
			if (di1[b[id]]+w[id]+di2[a[id]]==d) return 1;
			else return 0;
		}
	}
	return 0;
}

ll go1(){
	for (int i=1;i<=n;i++){
		u1[i]=0;
		di1[i]=0;
	}
	priority_queue<pair<ll, int> > dij;
	dij.push({0, s});
	while (!dij.empty()){
		auto x=dij.top();
		dij.pop();
		if (u1[x.S]) continue;
		u1[x.S]=1;
		di1[x.S]=-x.F;
		for (auto nx:g[x.S]){
			dij.push({x.F-w[nx.S], nx.F});
		}
	}
	if (u1[t]==0) return 1e10;
	return di1[t];
}

ll go2(){
	for (int i=1;i<=n;i++){
		u2[i]=0;
		di2[i]=0;
	}
	priority_queue<pair<ll, int> > dij;
	dij.push({0, t});
	while (!dij.empty()){
		auto x=dij.top();
		dij.pop();
		if (u2[x.S]) continue;
		u2[x.S]=1;
		di2[x.S]=-x.F;
		for (auto nx:g[x.S]){
			dij.push({x.F-w[nx.S], nx.F});
		}
	}
	if (u2[s]==0) return 1e10;
	return di2[s];
}

void ans(){
	cout<<"YES\n";
	for (int i=1;i<=m;i++){
		cout<<a[i]-1<<" "<<b[i]-1<<" "<<w[i]<<'\n';
	}
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll L;
	cin>>n>>m>>L>>s>>t;
	s++;
	t++;
	vector<int> un;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>w[i];
		a[i]++;
		b[i]++;
		g[a[i]].push_back({b[i], i});
		g[b[i]].push_back({a[i], i});
		if (w[i]==0) un.push_back(i);
	}
	ll mi=1;
	ll ma=1e9+1;
	ll lo=-1;
	ll up=-1;
	while (mi<=ma){
		ll mid=(mi+ma)/2;
		for (int u:un){
			w[u]=mid;
		}
		ll dt=go1();
		if (dt==L){
			ans();
		}
		if (dt<L){
			lo=mid;
			mi=mid+1;
		}
		else {
			up=mid;
			ma=mid-1;
		}
	}
	if (lo==-1||up==-1){
		cout<<"NO\n";
		return 0;
	}
	assert(lo+1==up);
	for (int u:un){
		w[u]=up;
	}
	go1();
	ll dis=go2();
	while (1){
		ll tt=0;
		for (int u:un){
			if (w[u]==up&&dis-tt>L&&is(u, dis)){
				w[u]=lo;
				tt++;
			}
		}
		dis=go1();
		if (dis==L) ans();
		go2();
	}
}
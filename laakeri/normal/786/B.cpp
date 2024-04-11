#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=1e17;
const int N=1<<17;
ll st1[2*N];
ll lz[2*N];
int ac[2*N];

void setmin(int, int, int, int, int, ll);

void golz(int i, int stl, int str){
	int m=(stl+str)/2;
	if (lz[i]<inf){
		setmin(i*2, stl, m, stl, m, lz[i]);
		setmin(i*2+1, m+1, str, m+1, str, lz[i]);
		lz[i]=inf;
	}
}

void setmin(int i, int stl, int str, int l, int r, ll v){
	if (stl>r||str<l) return;
	if (!ac[i]) return;
	if (l<=stl&&str<=r){
		st1[i]=min(st1[i], v);
		lz[i]=min(lz[i], v);
	}
	else{
		golz(i, stl, str);
		int m=(stl+str)/2;
		setmin(i*2, stl, m, l, r, v);
		setmin(i*2+1, m+1, str, l, r, v);
		st1[i]=min(st1[i*2], st1[i*2+1]);
	}
}

void deac(int i, int stl, int str, int k){
	if (stl>k||str<k) return;
	if (!ac[i]) return;
	if (k<=stl&&str<=k){
		ac[i]=0;
		st1[i]=inf;
	}
	else{
		golz(i, stl, str);
		int m=(stl+str)/2;
		deac(i*2, stl, m, k);
		deac(i*2+1, m+1, str, k);
		st1[i]=min(st1[i*2], st1[i*2+1]);
		ac[i]=(ac[i*2]||ac[i*2+1]);
	}
}

pair<int, ll> getmin(int i, int stl, int str){
	if (!ac[i]) return {-1, inf};
	if (i>=N) return {stl, st1[i]};
	golz(i, stl, str);
	int m=(stl+str)/2;
	if (st1[i*2]<st1[i*2+1]) return getmin(i*2, stl, m);
	return getmin(i*2+1, m+1, str);
}

ll ans[101010];

vector<pair<pair<int, int>, ll> > go1[101010];

pair<int, int> st2[2*N];

set<pair<int, pair<int, ll> > > go2[101010];

pair<int, int> getmax(int a, int b){
	a+=N;
	b+=N;
	pair<int, int> ret={0, 0};
	while (a<=b){
		if (a%2) ret=max(ret, st2[a++]);
		if (!(b%2)) ret=max(ret, st2[b--]);
		a/=2;
		b/=2;
	}
	return ret;
}

void setv(int i, pair<int, int> v){
	st2[i+N]=v;
	for (i=(i+N)/2;i;i/=2){
		st2[i]=max(st2[i*2], st2[i*2+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,s;
	cin>>n>>q>>s;
	for (int i=0;i<2*N;i++){
		st1[i]=inf;
		ac[i]=1;
		lz[i]=inf;
	}
	for (int i=1;i<=n;i++){
		ans[i]=-1;
	}
	for (int i=0;i<q;i++){
		int t;
		cin>>t;
		if (t==1){
			int v,u;
			ll w;
			cin>>v>>u>>w;
			go1[v].push_back({{u, u}, w});
		}
		else if(t==2){
			int v,l,r;
			ll w;
			cin>>v>>l>>r>>w;
			go1[v].push_back({{l, r}, w});
		}
		else{
			int v,l,r;
			ll w;
			cin>>v>>l>>r>>w;
			go2[l].insert({r, {v, w}});
		}
	}
	for (int i=1;i<=n;i++){
		if (go2[i].size()>0){
			st2[i+N]={(*go2[i].rbegin()).F, i};
		}
	}
	for (int i=N-1;i>0;i--){
		st2[i]=max(st2[i*2], st2[i*2+1]);
	}
	setmin(1, 0, N-1, s, s, 0);
	while (1){
		auto ttt=getmin(1, 0, N-1);
		if (ttt.F<0) break;
		if (ttt.S>=inf) break;
		int x=ttt.F;
		ll d=ttt.S;
		assert(ac[x+N]==1);
		deac(1, 0, N-1, x);
		assert(ac[x+N]==0);
		ans[x]=d;
		while (1){
			auto mm=getmax(1, x);
			if (mm.F<x) break;
			auto lol=(*go2[mm.S].rbegin());
			go2[mm.S].erase(lol);
			if (go2[mm.S].size()>0){
				st2[mm.S+N]={(*go2[mm.S].rbegin()).F, mm.S};
			}
			else{
				st2[mm.S+N]={0, 0};
			}
			setv(mm.S, st2[mm.S+N]);
			setmin(1, 0, N-1, lol.S.F, lol.S.F, d+lol.S.S);
		}
		for (auto a:go1[x]){
			setmin(1, 0, N-1, a.F.F, a.F.S, d+a.S);
		}
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
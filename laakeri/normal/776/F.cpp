#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n;

int dt(pair<int, int> x){
	if (x.F<x.S) return x.S-x.F;
	return x.S+n-x.F;
}

vector<int> g[101010];

vector<int> tv[101010];

set<int> h[101010];

int pf[101010];

int col[101010];
int del[101010];
int aps[101010];

void dfs0(int x, int p){
	aps[x]=1;
	for (int nx:g[x]){
		if (nx==p) continue;
		if (del[nx]) continue;
		dfs0(nx, x);
		aps[x]+=aps[nx];
	}
}

int ct;

void dfs1(int x, int p, int sz){
	int ma=0;
	for (int nx:g[x]){
		if (nx==p) continue;
		if (del[nx]) continue;
		ma=max(ma, aps[nx]);
	}
	if (max(ma, sz-aps[x])<=sz/2){
		ct=x;
	}
	for (int nx:g[x]){
		if (nx==p) continue;
		if (del[nx]) continue;
		dfs1(nx, x, sz);
	}
}

void solve(int x, int cc){
	dfs0(x, -1);
	ct=-1;
	dfs1(x, -1, aps[x]);
	assert(ct!=-1);
	assert(cc<=20);
	col[ct]=cc;
	del[ct]=1;
	for (int nx:g[ct]){
		if (!del[nx]){
			solve(nx, cc+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	if (m==0){
		cout<<1<<endl;
		return 0;
	}
	vector<pair<int, int> > iv;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if (a>b) swap(a, b);
		int d1=b-a;
		int d2=a+n-b;
		if (d1<d2){
			iv.push_back({a, b});
		}
		else{
			iv.push_back({b, a});
		}
	}
	auto cmp = [](pair<int, int> a, pair<int, int> b) {
		return dt(a)<dt(b);
	};
	sort(iv.begin(), iv.end(), cmp);
	set<int> ver;
	for (int i=0;i<n;i++){
		ver.insert(i);
	}
	for (int i=0;i<m;i++){
		tv[i].push_back(iv[i].F);
		tv[i].push_back(iv[i].S);
		set<int> adj;
		if (iv[i].F<iv[i].S){
			auto it=ver.lower_bound(iv[i].F+1);
			while (it!=ver.end()&&(*it)>iv[i].F&&(*it)<iv[i].S){
				for (int a:h[*it]){
					adj.insert(a);
				}
				tv[i].push_back(*it);
				auto lol=it;
				it++;
// 				cout<<"er "<<(*lol)<<endl;
				ver.erase(lol);
			}
		}
		else{
			auto it=ver.lower_bound(iv[i].F+1);
			while (it!=ver.end()){
				for (int a:h[*it]){
					adj.insert(a);
				}
				tv[i].push_back(*it);
				auto lol=it;
				it++;
// 				cout<<"er "<<(*lol)<<endl;
				ver.erase(lol);
			}
			it=ver.begin();
			while (it!=ver.end()&&(*it)<iv[i].S){
				for (int a:h[*it]){
					adj.insert(a);
				}
				tv[i].push_back(*it);
				auto lol=it;
				it++;
// 				cout<<"er "<<(*lol)<<endl;
				ver.erase(lol);
			}
		}
// 		cout<<iv[i].F<<" t "<<iv[i].S<<endl;
		for (int a:adj){
			if (pf[a]) continue;
// 			cout<<"a "<<a<<endl;
			pf[a]=1;
			g[a].push_back(i);
			g[i].push_back(a);
		}
		h[iv[i].F].insert(i);
		h[iv[i].S].insert(i);
	}
	for (int x:ver){
		tv[m].push_back(x);
	}
	for (int i=0;i<m;i++){
		if (pf[i]==0){
			g[m].push_back(i);
			g[i].push_back(m);
			pf[i]=1;
		}
	}
	for (int i=0;i<=m;i++){
		sort(tv[i].rbegin(), tv[i].rend());
	}
	solve(m, 1);
	vector<pair<vector<int>, int> > asdf;
	for (int i=0;i<=m;i++){
		asdf.push_back({tv[i], col[i]});
	}
	sort(asdf.begin(), asdf.end());
	for (int i=0;i<=m;i++){
		/*
		for (int a:asdf[i].F){
			cout<<a<<" ";
		}
		cout<<endl;*/
		cout<<asdf[i].S<<" ";
// 		cout<<endl;
	}
	cout<<endl;
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
const int maxN = 100000 + 10; 
const int maxS = 500;

int par[maxN];
vector<pair<int,int>> e[maxN];

pair<int,int> que[maxN];

int ff( int s ) { 
	return par[s] < 0 ? s : par[s] = ff(par[s]) ;
}
void gg( int u , int v ) { 
	u = ff(u); v = ff(v);
	if( u == v ) return;
	if(par[u] > par[v]) swap(u,v);
	par[u] += par[v];
	par[v] = u;
}

int ans[maxN];
map<int,int> used[maxN];

int tmp[maxN];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v,c; cin >> u >> v >> c;
		u--; v--; c--;
		e[c].push_back({u,v});
	}
	int q; cin >> q;
	for( int i = 0 ; i < q ; i++ ) {
		cin >> que[i].first >> que[i].second;
		que[i].first-- ; que[i].second--; 
		if( que[i].first > que[i].second ) swap(que[i].first,que[i].second);
	} 
	memset(par,-1,sizeof par);
	int sz; 
	for( int i = 0 ; i < m ; i++ ) { 
		for( auto x : e[i] ) gg( x.first, x.second );
		if( sz(e[i]) >= maxS ) {
			for( int j = 0 ; j < q ; j++ ) 
				if( ff(que[j].first) == ff(que[j].second) ) ans[j]++;
		} else {
			sz=0;
			for( auto x : e[i] ) {
				tmp[sz++] = x.first;
				tmp[sz++] = x.second;
			}
			sort(tmp,tmp+sz);
			sz = unique(tmp,tmp+sz) - tmp;
			for( int k = 0 ; k < sz ; k++ ) 
				for( int j = k + 1 ; j < sz ; j++ ) 
					if( ff(tmp[k]) == ff(tmp[j]) ) used[tmp[k]][tmp[j]]++;
		}
		for( auto x : e[i] ) par[x.first] = par[x.second] = -1;
	}
	for( int i = 0 ; i < q ; i++ ) 
		cout << ans[i] + used[que[i].first][que[i].second] << '\n';
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10; 
vector<int> c[maxN];
vector<int> e[maxN];
int start[maxN]; 
int sz;
int ans ; 

int lo[maxN];
int mark[maxN];
int cnt[maxN];
stack<int> curr; 

int tarjan( int s ) { 
	mark[s] = 1;
	curr.push(s);
	static int ind = 0; 

	int num = lo[s] = ind++;

	for( auto x : c[s] ) 
		if( !mark[x] ) 
			lo[s] = min(lo[s],tarjan(x));
		else if( mark[x] == 1 ) 
			lo[s] = min(lo[s],lo[x]);

	if( lo[s] == num ) { 
		start[sz++] = lo[s];
		while(1) { 
			cnt[lo[s]]++;
			int x = curr.top(); curr.pop();
			mark[x] = 2; 
			lo[x] = lo[s];
			for( auto y : c[x] ) 
				if( mark[y] == 2 && lo[y] != lo[x] ) {
					e[lo[x]].push_back(lo[y]);
					e[lo[y]].push_back(lo[x]);
				}

			if( x == s ) break;
		}
	}
	return lo[s];
}

bool hasOne;
int dfs( int s ) {
	mark[s] = true;
	if( cnt[s] > 1 ) hasOne = true;
	int ret = cnt[s];
	for( auto x : e[s] ) 
		if( !mark[x] ) 
			ret += dfs(x);
	return ret;
}

int main() { 
	int n,m;
	cin >> n >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v);
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( !mark[i] ) 
			tarjan(i);
	reverse(start, start + sz) ; 

//	cout << "TMP " << ans << endl;
	memset(mark,0,sizeof mark);
	for( int i = 0 ; i < sz ; i++ ) 
		if( !mark[start[i]] ) {
			hasOne = false;
			int v = dfs(start[i]);
			if( !hasOne ) v--;
//			cout << "SZ: " << v << endl;
			ans += v;
		}
	cout << min(n,ans) << endl;
}
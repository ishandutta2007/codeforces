//IN the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5 * 1000 * 100 + 100; 
const int maxK = 50 + 2; 
typedef pair<int,int> edge; 

inline void term( bool ch , string s ) { 
	if( ch ) { 
		cout << s << endl;
		exit(0);
	}
}

int par[maxK][maxN];
bool rev[maxK][maxN];
int dfind( int u , int id ) { 
	return par[id][u] < 0 ? u : dfind( par[id][u] , id );
}
bool dcol( int u , int id ) {
	return par[id][u] < 0 ? rev[id][u] : dcol( par[id][u] , id ) ^ rev[id][u];
}

vector<pair<int,int>> dolist[maxK];
void dmerge( int u , int v , int id ) { 
	//cerr << "!! " << id << endl;
	int a = dfind(u, id), b = dfind(v, id);
	if( a == b ) {
		dolist[id].push_back({-1,-1});
		return;
	}
	if( par[id][a] < par[id][b] ) 
		swap(a , b);
	dolist[id].push_back({a,par[id][a]});
	par[id][b] += par[id][a];
	par[id][a] = b;
	if( dcol(u,id) == dcol(v,id) ) rev[id][a] ^= 1; 
}

void dundo( int id ) {
	auto x = dolist[id].back();
	dolist[id].pop_back();
	if( x.first != -1 )  {
		par[id][par[id][x.first]] -= x.second;
		par[id][x.first] = x.second;
	}
}

edge e[maxN];
int last[maxN], co[maxN], curr[maxN];
pair<int,int> que[maxN];
int n,m,k,q; 

vector<int> toadd[4*maxN];
void add( int ql , int qr , int xl = 0 , int xr = q , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) { 
		toadd[ind].push_back( ql );
		return;	
	}
	int xm = (xl+xr)/2; 
	add( ql , qr , xl , xm , ind * 2 ); 
	add( ql , qr , xm , xr , ind * 2 + 1 ); 
}

void solve( int xl = 0 , int xr = q , int ind = 1 ) { 
	for( auto x : toadd[ind] ) { 
		int id = que[x].first; 
		dmerge( e[id].first , e[id].second , co[x] = curr[id] ); 
	}

	if( xr - xl == 1 ) { 
		int id = que[xr].first, c = que[xr].second;
		if( dfind( e[id].first , c ) != dfind( e[id].second , c ) ||
				dcol( e[id].first , c ) != dcol( e[id].second , c ) ) {
			cout << "YES\n";
			curr[id] = c;
		} else cout << "NO\n";
	} else { 
		int xm = (xl+xr)/2; 
		solve( xl , xm , ind * 2 ); 
		solve( xm , xr , ind * 2 + 1 );
	}

	for( auto x : toadd[ind] ) 
		dundo( co[x] ); 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	memset( par , -1 , sizeof par );
	cin >> n >> m >> k >> q; 
	for( int i = 0; i < m; i++ ) { 
		cin >> e[i].first >> e[i].second;
		e[i].first--; 
		e[i].second--; 
	}
	for( int i = 1 ; i <= q ; i++ ) { 
		int x,c; cin >> x >> c; 
		x--;
		que[i] = { x , c }; 
		if( last[x] != 0 ) add( last[x] , i ); 
		last[x] = i;
	}
	for( int i = 0 ; i < m ; i++ ) 
		if( last[i] != 0 ) add( last[i] , q ); 
	solve();
}
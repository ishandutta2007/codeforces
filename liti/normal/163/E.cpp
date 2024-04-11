//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
const int maxL = 1000*1000 + 10; 
const int maxN = 1000*100 + 10;
const int maxK = 26;

inline int toInt( string s ) { 
	int ret = 0;
	for( auto x : s ) 
		ret = ret * 10 + x - '0';
	return ret; 
}

vector<pair<int,int>> nodes;
vector<int> c[maxL];
int h[maxL] , nex[maxL][maxK], fath[maxL], par[maxL];
short ch[maxL];
int ind[maxN];
bool used[maxN];

void makeAho() { 
	for( int i = 0 ; i < maxK ; i++ ) if( nex[0][i] == -1 ) 
		nex[0][i] = 0; 
	sort( nodes.begin() , nodes.end() ) ;  
	for( auto xt : nodes ) { 
		int x = xt.second; 
		if( par[x] != 0 ) 
			fath[x] = nex[fath[par[x]]][ch[x]]; 
		c[fath[x]].push_back( x ); 
		for( int i = 0 ; i < maxK ; i++ ) 
			if( nex[x][i] == -1 ) 
				nex[x][i] = nex[fath[x]][i];
	}
}

int st[maxL] , en[maxL];

void dfs( int s ) { 
	static int ind = 0;
	st[s] = ind++; 
	for( auto x : c[s] ) 
		dfs( x ) ; 
	en[s] = ind; 
}

int cnt; 
int sum[4*maxL];
void sVal( int ql , int qr , int v , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) {
		sum[ind] += v; 
		return; 
	}
	int xm = (xl+xr)>>1;
	sVal( ql , qr , v , xl , xm , ind * 2 ) ; 
	sVal( ql , qr , v , xm , xr , ind * 2 + 1 ) ; 
}
int gVal( int p , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr - xl == 1 ) 
		return sum[ind];
	int xm = (xl+xr)>>1;
	if( p < xm ) 
		return sum[ind] + gVal( p , xl , xm , ind * 2 ) ; 
	return sum[ind] + gVal( p , xm , xr , ind * 2 + 1 ) ; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	memset( nex , -1 , sizeof nex ); 
	int n , m; 
	cin >> m >> n; 

	cnt = 1;
	for( int i = 0 ; i < n ; i++ ) { 
		string s; 
		cin >> s;
		int curr = 0; 
		for( auto x : s ) {
			if( nex[curr][x-'a'] == -1 ) { 
				nex[curr][x-'a'] = cnt; 
				h[cnt] = h[curr] + 1;
				par[cnt] = curr;
				ch[cnt] = x - 'a';
				nodes.push_back( { h[cnt] , cnt } ) ; 
				cnt++; 
			}
			curr = nex[curr][x-'a'];
		}
		ind[i] = curr;
	}
	makeAho();
	dfs( 0 ); 
	for( int i = 0 ; i < n ; i++ ) { 
		used[i] = true;
		sVal( st[ind[i]] , en[ind[i]] , 1 ) ; 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		string s; 
		cin >> s; 
		string r = s.substr( 1 ) ; 
		if( s[0] == '+' ) { 
			int x = toInt( r ) ; 
			x--;
			if( !used[x] ) { 
				used[x] = true;
				sVal( st[ind[x]] , en[ind[x]] , 1 ) ; 
			}
		} else if( s[0] == '-' ) { 
			int x = toInt( r ) ; 
			x--;
			if( used[x] ) { 
				used[x] = false;
				sVal( st[ind[x]] , en[ind[x]] , -1 ) ; 
			}
		} else {
			int curr = 0; 
			ll ret = 0;
			for( auto x : r ) {
				curr = nex[curr][x-'a'];
				ret += gVal( st[curr] ) ; 
			}
			cout << ret << '\n'; 
		}
	}
}
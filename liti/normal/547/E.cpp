//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2 * 1000*100 + 100; 
const int maxK = 26; 

vector<int> c[maxN];

int nex[maxN][maxK], fath[maxN];
int ch[maxN];
int p[maxN];
int hei[maxN];
//string str[maxN];
vector<pair<int,int>> nodes;
int cnt;

inline void make_aho() { 
	sort( nodes.begin() , nodes.end() ) ; 
	for( int i = 0 ; i < maxK ; i++ ) 
		if( nex[0][i] == -1 ) nex[0][i] = 0;
	fath[0] = -1;
	for( auto xt : nodes ) { 
		int x = xt.second;
		if( p[x] != 0 ) 
			fath[x] = nex[fath[p[x]]][ch[x]];
		else
			fath[x] = 0;
	//	cout << x << ' ' << str[x] << ' ' << char(ch[x]+'a') << ' ' << fath[x] << endl;
		c[fath[x]].push_back( x ) ; 
		for( int i = 0 ; i < maxK ; i++ ) 
			if( nex[x][i] == -1 ) 
				nex[x][i] = nex[fath[x]][i];
	}
}

int ind[maxN];
vector<int> val[maxN];
int st[maxN], en[maxN], ptr[maxN];
vector<int> seg[4*maxN];

void dfs( int s = 0 ) { 
	static int ind = 0; 
	ptr[ind] = s; 
	st[s] = ind++; 
	for( auto x : c[s] ) 
		dfs( x ) ; 
	en[s] = ind; 
}

inline void make_tree( int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		seg[ind] = val[ptr[xl]]; 
		return;
	}
	int xm = (xl+xr)>>1; 
	make_tree( xl , xm , ind * 2 ) ; 
	make_tree( xm , xr , ind * 2 + 1 ); 
	seg[ind].resize( __sz(seg[ind*2]) + __sz(seg[ind*2+1])); 
	merge( seg[ind*2].begin() , seg[ind*2].end() , 
			seg[ind*2+1].begin() , seg[ind*2+1].end() , 
			seg[ind].begin() ) ; 
}
inline int gg( int l, int r , int ql ,int qr , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) 
		return lower_bound( seg[ind].begin() , seg[ind].end() , r ) 
			- lower_bound( seg[ind].begin() , seg[ind].end() , l ) ;
	int xm = (xl+xr)>>1; 
	int ret =0; 
	ret += gg( l , r , ql , qr , xl , xm , ind * 2 ) ; 
	ret += gg( l , r , ql , qr , xm , xr , ind * 2 + 1 ) ; 
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,q; 
	cin >> n >> q; 

	memset( nex , -1 , sizeof nex ) ; 
	cnt = 1;
	for( int i = 0 ; i < n ; i++ ) { 
		string s;
		cin >> s; 
		int curr = 0; 
		for( auto ch : s ) { 
			int x = ch - 'a';
			if( nex[curr][x] == -1 ) { 
				nex[curr][x] = cnt; 
//				str[cnt] = str[curr] + ch;
				p[cnt] = curr;
				hei[cnt] = hei[curr] + 1; 
				::ch[cnt] = x;
				nodes.push_back( { hei[cnt] , cnt } ) ; 
				cnt++;
			}
			curr = nex[curr][x] ; 
			val[curr].push_back(i);
		}
		ind[i] = curr;
	}
	make_aho();
	dfs(0);
	make_tree();
	for( int i = 0 ; i < q ; i++) { 
		int l,r,k; cin >> l >> r >> k; 
		l--; k--;
		int x = ind[k];
		cout << gg( l , r , st[x] , en[x] ) << '\n';
	}
}
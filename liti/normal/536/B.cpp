//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) ((int)(x).size())

const int maxN = 1000*1000 + 100; 

int nex[maxN]; 
int st[maxN]; 
int en[maxN];
vector<int> c[maxN];
int ind;
void dfs( int s ) { 
	st[s] = ind++; 
	for( auto x : c[s] ) 
		dfs( x ) ; 
	en[s] = ind;
}

int main() { 
	int n,m;
	string s;
	cin >> n >> m; 
	cin >> s;

	int curr = 0; 
	c[curr].push_back( 1 ) ;
	for( int i = 1 ; i < sz(s) ; i++ ) { 
		while( curr && s[i] != s[curr] ) 
			curr = nex[curr];
		if( s[curr] == s[i] ) 
			curr++;
		nex[i+1] = curr; 
		c[curr].push_back( i + 1 ) ; 
	}
	dfs( 0 ) ; 

	int len = 0;
	if( m != 0 ) { 
		int last; cin >> last;
		last--;
		len = sz(s) ; 
		int p = sz(s);
		for( int i = 1 ; i < m ; i++ ) { 
			int num ; cin >> num;
			num--;
			len += sz(s); 
			len -= max( 0 , last + p - num ) ;
			if( last + p - num > 0 ) { 
				int lfix = last + p - num;

				if( !(st[lfix] <= st[p] && st[p] < en[lfix]) ) { 
					cout << 0 << endl;
					return 0;
				}
			}
			last = num;
			//num >= last + p if correct
		}
	} else
		len = 0;

	ll ans = 1; 
	int mod = 1e9 + 7;
	len = n - len;
	for( int i = 0 ; i < len ; i++ ) 
		ans = ans*26LL % mod;
	cout << ans << endl;
}
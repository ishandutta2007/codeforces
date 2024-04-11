/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 100*1000 + 10; 
vector<pair<int,int>> c[maxN];

ll cnt[maxN];
int last[maxN];
ll ans = 0;
int n,m;

int dfs( int s , int p ) { 
	int ret = 1;
	for( auto x : c[s] ) 
		if( x.first != p ) { 
			int t = dfs( x.first , s ) ; 
			ans += t * ld( n - t ) * last[x.second];
			cnt[x.second] = t * ll(n-t) ;
			ret += t;
		}
	return ret;
}

int main() { 
	cin >> n ;

	for( int i = 0 ; i <  n - 1 ; i++ ) { 
		int x,y,w;
		cin >> x >> y >> w; 
		last[i] = w;
		x--; y--;
		c[x].push_back( {y,i} ) ; 
		c[y].push_back( {x,i} ) ;
	}
	dfs( 0 , -1 ) ; 

	int q;
	cin >> q;
	for( int i = 0 ; i < q ; i++ ) {
		int r,w;
		cin >> r >> w; r--;
		ans -= (last[r] - w)*cnt[r];
		last[r] = w;
		cout << fixed << setprecision(9) << 3*ans/ld(n*ld(n-1)/2) << endl;
	}
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 100;
const int mod = 1e9 + 9;
map<int,vector<pair<int,int>>> y; 
vector<int> c[maxN];
vector<int> cRev[maxN];
int out[maxN];
int used[maxN];

pair<int,int> a[maxN];
set<int> curr;
int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].first >> a[i].second;
		y[a[i].second+1].push_back( {a[i].first ,i} ) ;
	}
	for( auto & it : y ) 
		sort( it.second.begin() , it.second.end()); 
	for( int i = 0 ; i < n ; i++ ) if( a[i].second != 0 ) { 
		int ind = lower_bound( y[a[i].second].begin() , y[a[i].second].end() ,
				make_pair(a[i].first,0) )
			- y[a[i].second].begin();
		auto x = make_pair(0,0);

		if( ind != (int)y[a[i].second].size() && y[a[i].second][ind].first <= a[i].first + 1 ) {
			x = y[a[i].second][ind];
			c[i].push_back( x.second ) ;
			cRev[x.second].push_back(i);
			out[x.second]++;
		}
		if( ind != 0 ) { 
			x = y[a[i].second][ind-1];
			if( x.first + 1 >= a[i].first ) {
				c[i].push_back( x.second ) ;
				cRev[x.second].push_back(i);
				out[x.second]++;
			}
		}
		if( ind < (int)y[a[i].second].size() - 1 && y[a[i].second][ind+1].first <= a[i].first + 1 ) { 
			x = y[a[i].second][ind+1];
			c[i].push_back( x.second ) ;
			cRev[x.second].push_back(i);
			out[x.second]++;
		}
	}

	for( int i = 0 ; i < n ; i++ ) 
		if( out[i] == 0 ) 
			curr.insert(i);
	for( int i = 0 ; i < n ; i++ ) {
		bool ch = true;
		for( auto x : cRev[i] ) 
			if( c[x].size() == 1 ) 
				ch = false;
		if( ch ) {
			curr.insert(i);
		}
	}

	int turn = 1;
	int ans = 0;
	while( curr.size() ) { 
		auto it = curr.begin();
		if( turn == 1 ) { 
			it = curr.end();
			it--;
		}
		ans = ans*1ll*n % mod ;
		ans += *it;
		ans %= mod;
		int s = *it;
		curr.erase(it);
		used[s] = true;
		for( auto x : c[s] ) {
			out[x]--;
			if( used[x] ) continue;
			if( out[x] == 0 ) 
				curr.insert( x ) ;
			else { 
				bool ch = true;
				for( auto y : cRev[x] ) 
					if( !used[y]  ) {
						int cnt = 0;
						for( auto z : c[y] ) 
							cnt += 1 - used[z];
						if( cnt == 1 ) 
							ch = false;
					}
				if( ch ) {
					curr.insert(x);
				}
			}
		}
		for( auto x : cRev[s] ) if( !used[x] ) {
			int cnt =0;
			for( auto y : c[x] ) if( !used[y] ) 
				cnt++;
			if( cnt == 1 ) 
				for( auto y : c[x] ) if( !used[y] ) 
					curr.erase(y);
		}  

		turn ^= 1;
	}
	cout << ans << endl;
}
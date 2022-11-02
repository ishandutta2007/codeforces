//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 5 * 1000*100 + 10; 
vector<int> p[maxN]; 
bool pr[maxN];
int cnt[maxN];
int a[maxN];

int used[maxN];

inline void add( int num , int val ) { 	
	int k = __sz(p[num]);
	for( int i = 0 ; i < (1<<k) ; i++ ) { 
		int x =1; 
		for( int j =0 ; j < k ; j++ ) if( (i>>j) & 1 ) 
			x *= p[num][j]; 
		cnt[x] += val;
	}
}

int calc( int num ) { 
	int k = __sz(p[num]);
	int ret = 0;
	for( int i = 0 ; i < (1<<k) ; i++ ) { 
		int x =1; 
		for( int j =0 ; j < k ; j++ ) if( (i>>j) & 1 ) 
			x *= p[num][j]; 
		if( __builtin_popcount(i) & 1 ) 
			ret -= cnt[x];
		else
			ret += cnt[x];
	}
	return ret;
}

int main() { 
	ios::sync_with_stdio(false);

	for( int i = 2 ; i < maxN ; i++ ) if( !pr[i] ) { 
		for(int j = i ; j < maxN ; j += i ) {
			p[j].push_back( i ) ; 
			pr[j] = true;
		}
	}

	int n,q; 
	cin >> n >> q; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	ll ans = 0;
	for( int i = 0 ; i < q ; i++ ) { 
		int x; 
		cin >> x;
		x--;
		if( used[x] ) { 
			add(a[x],-1); 
			ans -= calc( a[x] );
			used[x] = false;
		} else { 
			ans += calc( a[x] );
			add(a[x],1); 
			used[x] = true;
		}
		cout << ans << '\n';
	}
}
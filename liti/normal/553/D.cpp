//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld;

const int maxN = 100 * 1000 + 10; 

vector<int> c[maxN];
int val[maxN];
int bad[maxN];


int n,m,k; 

int used[maxN]; 
int que[maxN];
int req[maxN];
vector<int> ans;
bool check( ld v , bool pr = false ) { 
	memset( used , 0 , sizeof used ) ; 
	memset( req , 0 , sizeof req ) ; 
	int en = 0;
	for( int i = 0 ; i < n ; i++ ) if( !bad[i] ) { 
		int all = val[i] + __sz(c[i]); 
		int x = ceil( all * v ) ; 
		if( x > __sz(c[i]) ) { 
			que[en++] = i;
			used[i] = true;
			continue;
		}
		req[i] = __sz(c[i]) - x;
//		cout << " " << i + 1 << ' ' << x  << ' ' << req[i] << endl;
	} else {
		que[en++] = i; 
		used[i] = true;
	}
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		for( auto x : c[s] ) { 
			req[x]--; 
			if( req[x] == -1 && !used[x] ) {  
				que[en++] = x;  
				used[x] = true; 
			}
		}
	}

	int cnt = 0;
	for( int i = 0 ; i < n ; i++) if( !used[i] ) {
		cnt++;
		if( pr ) ans.push_back( i ) ; 
	}

	if( pr ) { 
		cout<< __sz(ans) << endl;
		for( int i = 0 ; i < __sz(ans) ; i++ ) 
			cout << ans[i] + 1 << ' ' ; 
		cout << endl;
	}

	return cnt > 0; 
}

int main() { 
	ios::sync_with_stdio(false);
	cin >> n >> m >> k; 
	for( int i = 0 ; i < k; i++ ) {
		int x; cin >> x;  x--;
		bad[x] = true; 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		int a,b; cin >> a >> b; 
		a--; b--; 
		if( bad[a] ) 
			val[b]++; 
		else if( bad[b] ) 
			val[a]++; 
		else { 
			c[a].push_back( b ); 
			c[b].push_back( a ) ; 
		}
	}
	ld s = 0 , e = 1 + 1e-8; 
	for( int i = 0 ; i < 200 ; i++ ) { 
		ld mid = (s+e) / 2; 
		if( check( mid ) )
			s = mid; 
		else 
			e = mid;
	}
//	cout << s << endl;
	check( s , 1 ) ; 

//	cout << check( 0.5 ) << endl;
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;
const int maxW = 200*100*100 + 10;
typedef pair<int,int> pii;

template <class T>
inline void smax( T& a , const T b ) {
	a = max( a ,b ) ;
}

vector<int> c[maxN];

int a[maxN];
pii ans[maxN];
map<int,stack<pii>> curr;

vector<int> p[maxW];
bool gh[maxW];

void doJob( int s = 1 , int p = 0 , int h = 1 ) { 
	ans[s] = {0,-1};
	for( auto x : ::p[a[s]] ) {
		if( !curr[x].empty() )
			smax( ans[s] , curr[x].top() ) ;
		curr[x].push({h,s});
//		cout << x << ' ' << h << ' ' << s << ' ' << a[s] << endl;
	}

	for( auto x : c[s] ) 
		if( x != p ) 
			doJob( x , s , h + 1 ) ; 
	for( auto x : ::p[a[s]] ) 
		curr[x].pop();
}

int main() { 
	ios::sync_with_stdio(false);
	for( int i = 2  ; i < maxW ; i++ ) 
		if( !gh[i] ) 
			for( int j = i ; j < maxW ; j += i ) {
				gh[j] = true;
				p[j].push_back( i ) ; 
			}

	int n,q;
	cin >> n >> q;

	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i+1];
	for( int i = 0 ; i < n- 1 ;i++ ) { 
		int x,y;
		cin >> x >> y;
		c[x].push_back(y);
		c[y].push_back(x);
	}

//	cout << endl ;
	doJob() ; 

	for( int i = 0 ; i < q ; i++ ) { 
		int t;
		cin >> t;
		if( t == 1 ) { 
			int v;
			cin >> v;
			cout << ans[v].second << endl;
		} else { 
			int v , w;
			cin >> v >> w;
			a[v] = w;
			doJob() ; 
		}
	}
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 1000 + 10; 

int fen[maxN]; 
inline void add( int x , int v ) { 
	x++; 
	for( ; x < maxN ; x += x & (-x) ) 
		fen[x] += v; 
}
inline int get( int x ) { 
	int ret = 0; 
	for( ; x ; x -= x & -x ) 
		ret += fen[x]; 
	return ret; 
}

int t[maxN]; 
int que[maxN]; 

int ans[maxN]; 

pair<int,int> a[maxN];
set<int> curr; 

vector<int> X; 
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		int tp , x , time; cin >> tp >> time >> x; 
		a[i] = { x , i } ; 
		t[i] = tp ; que[i] = time; 
		X.push_back(time); 
	} 
	sort( X.begin() , X.end() ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		que[i] = lower_bound(X.begin(),X.end(),que[i]) - X.begin() ;
	sort( a , a + n ) ; 
	int j;
	for( int i = 0 ; i < n ; i = j ) {
		for( j = i ; j < n && a[i].first == a[j].first ; j++ ) ; 
		for( int k = i ; k < j ; k++ ) { 
			int ind = a[k].second; 
			if( t[ind] == 1 ) { 
				add( que[ind] , 1 ) ; 
			} else if( t[ind] == 2 ) { 
				add( que[ind] , -1 ) ; 
			} else 
				ans[ind] = get( que[ind] ) ;
		}
		for( int k = i ; k < j ; k++ ) { 
			int ind = a[k].second; 
			if( t[ind] == 1 ) 
				add( que[ind] , -1 ) ; 
			else if( t[ind] == 2 )
				add( que[ind] , 1 ) ; 
		}
	}
	for( int i = 0 ; i < n; i++ ) 
		if( t[i] == 3 ) 
			cout << ans[i] << '\n';
}
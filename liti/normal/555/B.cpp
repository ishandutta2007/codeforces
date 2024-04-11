//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define __sz(x) ((int)(x).size())

const int maxN = 2 * 1000 * 100 + 10; 
pair<pair<int,int>,int> a[maxN]; 
pair<ll,ll> b[maxN];
pair<ll,int> c[maxN];

int ans[maxN];

set<pair<int,int>> curr;
int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; 
	cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> b[i].first >> b[i].second;
	for( int i = 0 ; i < m ; i++ ) {  
		cin >> c[i].first ; 
		c[i].second  =i; 
	}
	sort( c , c + m );
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		a[i].second = i; 
		ll mn = b[i+1].first - b[i].second;
		ll mx = b[i+1].second - b[i].first;
		a[i].first.first = lower_bound( c , c + m , pair<ll,int>(mn,0) ) - c ; 
		a[i].first.second = upper_bound( c , c + m , pair<ll,int>(mx,m + 1) ) - c ;
	}
	sort( a , a + n - 1 ) ; 
	int j;
	int last = 0;
	a[n-1].first.first = m;
	for( int i = 0 ; i < n - 1  ; i = j ) { 
		for( j = i ; j < n  - 1 ; j++ ) {
			if( a[j].first.first != a[i].first.first ) 
				break;
			curr.insert( { a[j].first.second , a[j].second } ) ; 
		}
		last = max( last , a[i].first.first ) ; 
		while( curr.size() && curr.begin()->first > last && last < a[j].first.first ) { 
			ans[curr.begin()->second] = c[last].second; 
			curr.erase(curr.begin());
			last++;
		}
	}
	if( curr.size() ) 
		cout << "No" << endl;
	else { 
		cout << "Yes" << endl;
		for( int i = 0 ; i < n - 1 ; i++ ) 
			cout << ans[i] + 1 << ' ';
	}
}
//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 200 * 1000 + 10; 
pair<int,int> a[maxN];
int nx[maxN];

stack<int> curr; 
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	int d,n,m; 
	cin >> d >> n >> m; 
	for( int i = 0 ; i < m ; i++ ) 
		cin >> a[i].first >> a[i].second;
	sort( a , a + m ) ; 
	a[m].first = d; 
	curr.push( m ); 
	for( int i = m - 1 ; i >= 0 ; i-- ) { 
		while( curr.size() > 1 && a[curr.top()].second >= a[i].second ) 
			curr.pop(); 
		nx[i] = curr.top();
		curr.push(i);
	}
	int fuel = n; 
	ll cost = 0; 
	for( int i = 0 ; i <= m ; i++ ) { 
		fuel -= a[i].first - (i?a[i-1].first:0);
		if( fuel < 0 ) { 
			cout << -1 << endl;
			return 0; 
		}
		if( i == m ) break;
		int x = min( n - fuel , max(0,a[nx[i]].first - a[i].first - fuel) ); 
		fuel += x; 
		cost += a[i].second * 1ll * x ; 
		//cerr << a[i].first << ' ' << fuel << ' ' << cost << "  " << x << ' ' << nx[i] << endl;
	}
	cout << cost << endl;
}
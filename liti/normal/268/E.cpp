//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld;

const int maxN = 50 * 1000 + 10;
pair<int,int> a[maxN];
inline bool cmp( pair<int,int> a , pair<int,int> b ) { 
	return a.first * a.second * ( 100 - b.second ) >
		b.first * b.second * (100 - a.second) ; 
}


int main() { 
	ios::sync_with_stdio(false);
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].first >> a[i].second ;
	sort( a , a + n , cmp ); 
	ld x = 0;
	ld ans = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		ld p = a[i].second / 100.l , l = a[i].first;
		ans += l; 
		ans += ( 1 - p ) * x; 
		x = x + p * l;
	}
	cout << fixed << setprecision(9) << ans << endl;
}
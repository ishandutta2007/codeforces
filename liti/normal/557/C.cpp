//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 * 100 + 10; 

int cnt[300]; 
pair<int,int> a[maxN];

int main() { 
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i].first;
	int sum = 0;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].second;
		sum += a[i].second;
	}

	sort( a , a + n ) ; 
	int j; 
	int ret = 1000*1000*1000;
	for( int i = 0 ; i < n ; i=j ) { 
		int tmp = 0;
		for( j = i ; j < n ; j++ ) 
			if( a[j].first != a[i].first ) break;
			else tmp += a[j].second;
		int rem = min( i , j - i - 1 ) ;
		for( int k = 200 ; k >= 0 ; k-- ) { 
			tmp += k * min( rem, cnt[k] ) ; 
			rem -= min( rem , cnt[k] ) ; 
		} 
		if( rem == 0 ) 
			ret = min( ret , sum - tmp ) ; 
		for( int k = i ; k < j ; k++ ) 
			cnt[a[k].second]++;
	}
	cout << ret << endl;
}
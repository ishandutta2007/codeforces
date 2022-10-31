/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;

set<pair<int,int> > curr;
int a[maxN], b[maxN], p[maxN];
int ret[maxN];

int main() { 
	ios::sync_with_stdio(false);
	int n;
	cin >> n; 

	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		a[i]--;
		p[a[i]] = i;
	}

	for( int j = 0 ; j < n ; j++ ) {
		int num;
		cin >> num;
		num--;
		b[j] = j - p[num] ;
		curr.insert( {b[j],j} ) ; 
	}

	int cnt = 0 ; 
	for( int i = n - 1 ; i >= 0 ; i-- ) { 
		set<pair<int,int>>::iterator it = curr.lower_bound( {cnt,0} ) ;
		int ans = n;
		if( it != curr.end() ) {
			ans = min( ans, abs(  it->first - cnt ) ) ;
		}
		if( it != curr.begin() )
			ans = min( ans, abs ( (--it)->first - cnt )  ) ; 
		ret[ ( i + 1 ) % n ] = ans;

		cnt--;
		curr.erase( {b[i], i} ) ; 
		curr.insert( {cnt - (-b[i] + i)  , i}  ) ;
	}

	for( int i = 0 ; i < n ;i++ ) 
		cout << ret[i] << endl;
}
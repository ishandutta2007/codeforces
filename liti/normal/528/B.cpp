/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
const int maxN = 2000*100 + 100; 

vector<pair<int,int>> a;

bool cmp( pair<int,int> a , pair<int,int> b ) { 
	if( a.second== b.second ) 
		return a.first < b.first;
	return a.second < b.second; 
}

int main() { 
	int n;
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x,w;
		cin >> x >> w; 
		a.push_back( { x - w  , x + w } ) ; 
	}
	sort( a.begin() , a.end() , cmp ) ; 
	int cnt = 0 ;
	int last = -1e9 - 1000;
	for( int i = 0 ; i < n ; i++ ) { 
		if( a[i].first >= last ) { 
			cnt++; 
			last = a[i].second;
		}
	}
	cout << cnt << endl;
}
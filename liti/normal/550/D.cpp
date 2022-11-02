//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

vector<pair<int,int>> edges = { 
	{0,1},{1,3},{3,5},{5,7},
	{7,9},{9,1},{9,5},{3,7},
	{0,2},{2,4},{4,6},{6,8},
	{8,0},{8,4},{2,6} } ;
int main()  { 
	ios::sync_with_stdio(false);
	int k; 
	cin >> k; 
	if( k % 2 == 0 ) { 
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if( k == 1 ) { 
		cout << "2 1\n1 2" << endl;
		return 0; 
	}
	int n = 10; 
	for( int i = 3 ; i < k ; i+=2 ) {
		for( int x = n ; x < n + 4 ; x++ )
			for( int j = 0 ; j < n ; j++ ) if( x % 2 == j % 2 ) 
				edges.push_back({x,j});
		n += 4;
	}
	cout << n << ' ' << edges.size() << endl;
	for( int i = 0 ; i < __sz(edges) ; i++ ) 
		cout << edges[i].first +1 << ' ' << edges[i].second + 1 << endl;
}
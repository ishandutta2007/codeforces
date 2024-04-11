//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

vector<pair<int,int>> ans;
int main() { 
	int x,y,a,b; 
	cin >> x >> y >> a >> b; 
	for( int i = a ; i <= x ; i++)
		for( int j = b ; j <= y ; j++ ) 
			if( i > j ) 
				ans.push_back( { i , j } ); 
	sort( ans.begin() , ans.end() ) ;
	cout << __sz(ans) << endl;
	for( int i = 0 ;i < __sz(ans) ; i++ )
		 cout << ans[i].first << ' '<< ans[i].second << endl;
}
//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100 + 10;
string a[maxN];

int used[maxN]; 
set<pair<int,int>> curr; 
int b[maxN];
int main() { 
	int n; 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i] ;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> b[i];
		curr.insert( { b[i] , i } ); 
	}
	vector<int> ans; 
	while( curr.size() && curr.begin()->first == 0 ) {
		int s = curr.begin()->second;
		for( int i = 0 ; i < n ; i++ ) if( a[s][i] == '1' ) { 
			curr.erase( { b[i] , i } ) ; 
			b[i]--;
			if( b[i] >= 0 ) 
				curr.insert( { b[i] , i } ) ; 
		}
		ans.push_back( s ) ; 
	}
	cout << __sz(ans) << endl;
	for( int i = 0 ;i  < __sz(ans) ; i++ ) 
		cout << ans[i] + 1 << ' ' ;
	cout << endl;
}
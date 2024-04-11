//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef pair<int,int> pii; 

pii a[3]; 
vector<pii> ans; 

void calc( int i , int j , int k ) { 
	int dx = a[j].first - a[i].first; 
	int dy = a[j].second - a[i].second; 

	pii nex = { a[k].first + dx , a[k].second + dy } ; 
	if( nex != a[0] && nex!=a[1] && nex!=a[2] ) 
		ans.push_back(nex);
}

int main() { 
	for( int i = 0 ; i < 3 ; i++ ) 
		cin >> a[i].first >> a[i].second; 

	calc( 0 , 2 , 1 ); 
	calc( 2 , 0 , 1 ); 
	calc( 0 , 1 , 2 ); 
	calc( 1 , 0 , 2 ); 
	calc( 1 , 2 , 0 ); 
	calc( 2 , 1 , 0 ); 

	sort( ans.begin() , ans.end() ) ; 
	ans.resize( unique(ans.begin(),ans.end()) - ans.begin()); 
	cout << ans.size() << endl;
	for( auto x : ans ) 
		cout << x.first << " " << x.second << endl; 
}
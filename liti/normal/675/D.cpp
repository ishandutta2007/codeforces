//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

set<pii> curr; 
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); //XXX remember scanf
	int n; cin >> n;
	int x; cin >> x; curr.insert( {x,0} ); 
	curr.insert( {0,-1} ); 
	curr.insert( {int(1e9+10),-1} ); 
	for( int i = 1 ; i < n ; i++ ) { 
		int x; 
		cin >> x; 
		auto it = curr.lower_bound({x,i}); 
		auto v = *it; 
		if( v.second > (--it)->second ) cout << v.first << ' ';	
		else cout << it->first << ' ';
		curr.insert({x,i}); 
	}
	cout << endl;
}
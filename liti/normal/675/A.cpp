//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); //XXX remember scanf
	ll a,b,c; cin >> a >> b >> c; 
	// a + c x = b => x = ( b - a ) / c 
	if( c == 0 ) 
		cout << (a==b?"YES":"NO") << endl;
	else
		cout << (abs( b - a ) % abs( c ) == 0 && (b-a)/c >= 0 ? "YES" : "NO" ) << endl;

}
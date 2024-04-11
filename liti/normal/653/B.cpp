//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;

const int maxQ = 40; 
string a[maxQ] , b[maxQ]; 
int ans = 0; 
int n,q; 
void bt( int step , char curr = 'z' ) { 
	if( step == n ) { 
	   	ans += (curr == 'a');  
		return; 
	}
	if( step == 0 ) 
		for( char x = 'a' ; x <= 'f' ; x++ ) 
			bt( 1 , x );  
	else { 
		string s; s += curr; 
		for( char x = 'a' ; x <= 'f' ; x++ ) { 
			s += x; 
			for( int j = 0 ; j < q ; j++ ) 
				if( a[j] == s ) 
					bt( step + 1 , b[j][0] ) ; 
			s.pop_back(); 
		}
	}
}

int main() { 
	cin >> n >> q; 
	for( int i = 0 ; i < q ; i++ ) 
		cin >> a[i] >> b[i]; 
	bt(0); 
	cout << ans << endl;
}
//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define SZ(x) ((int)(x).size())    
typedef long long ll    ;

vector<int> num;
int main() { 

    for( int i = 1 ; i < (1<<7) ; i++) { 
	int x = 0; 
	for( int j = 6 ; j >= 0  ; j-- ) 
	    x = x * 10 + ( ( i & (1<<j) ) ? 1 : 0 ) ; 
	num.push_back( x ) ; 
    }

    string s;
    cin >> s;
    int n = s.size();
    vector<string> ans;
    for( int i = 0 ; i < 9 ; i++ ) {
	int x = 10;
	for( int i = 0 ; i <n  ; i++) 
	    if( s[i] - '0' > 0 ) 
		x = min( s[i] - '0'  , x ) ; 
	if( x == 10 ) break;
	string ret = "";
	bool ch = false;
	for( int j = 0 ; j < n; j++ ) 
	    if( s[j] - '0' > 0 ) { 
		s[j]--;
		ret += '1';
		ch = true;
	    }
	    else if( ch ) 
		ret += '0';
	ans.push_back( ret ) ; 
    }
    cout << ans.size() << endl;
    for( int i = 0 ; i < ans.size() ; i++ ) 
	cout << ans[i] << ' ' ;

}
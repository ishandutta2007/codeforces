//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
    int n;
    cin >> n;
    vector<int> ans;
    for( int i =0 ; i < n ; i++ ) { 
	bool ch = true; 
	for( int j = 0 ;j < n ; j++ ) { 
	    int num ; cin >> num; 
	    if( num == 1 || num == 3  ) 
		ch = false;
	}
	if( ch ) ans.push_back( i + 1 ) ; 
    }
    cout << __sz(ans) << endl;
    for( int i = 0 ; i < __sz(ans) ; i++ ) 
	cout << ans[i] << ' ' ; 
    cout << endl;
}
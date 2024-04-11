//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 + 100; 
int main() { 
	int n; 
	cin >> n; 
	vector<int> ans;
	for( int i = 2 ; i <= n ; i++ ) { 
		int num = i;
		for( int j = 2 ; j < i ; j++ ) 
			if( num % j == 0 ) { 
				while( num % j == 0 ) 
					num /= j; 
				break;
			}
		if( num == i || num == 1 ) ans.push_back( i ) ; 
	}
	cout << ans.size() << endl;
	for( int i = 0 ; i < __sz(ans) ; i++ ) 
		cout << ans[i] << ' ' ; 
	cout << endl;
}
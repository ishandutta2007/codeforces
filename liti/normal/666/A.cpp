//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 1000 * 10 + 100; 
set<string> ans;
int dp[maxN][2]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	string s; cin >> s; 
	int n = s.size();
	for( int i = n - 2 ; i > 4 ; i-- ) { 
		string a = s.substr( i , 2 ) ; 
		if( i + 2 == n || dp[i+2][1] || (dp[i+2][0] && a != s.substr(i+2,2)) ) { 
			dp[i][0] = 1; 
			ans.insert( a ) ; 
		} 
		if( i + 3 > n ) continue;
		string b = s.substr( i , 3 ) ; 
		if( i + 3 == n || dp[i+3][0] || (dp[i+3][1] && b != s.substr(i+3,3)) ) {
			dp[i][1] = 1; 
			ans.insert( b ) ; 
		}
	}

	cout << ans.size() << endl; 
	for( auto x : ans ) cout << x << endl;
}
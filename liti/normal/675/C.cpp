//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 100 * 1000 + 10; 

map<ll,int> curr; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); //XXX remember scanf

	int n; cin >> n; 
	ll sum = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		sum += x; 
		curr[sum]++; 
	}
	int ans =0; 
	for( auto x : curr ) ans = max( ans , x.second ) ; 
	cout << n - ans << endl;
}
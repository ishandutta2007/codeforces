//In the name of Allah
#include <bits/stdc++.h>

using namespace std;
#define __sz(x) ((int) x.size())
typedef long long ll;

const int maxN = 500 * 500 + 100;
multiset<int,greater<int>> curr;
int a[maxN];

int main() { 
	int n; 
	cin >> n; 
	n = n * n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i]; 
		curr.insert( a[i] ) ; 
	}
	vector<int> ans;
	while( curr.size() ) {
		int x = *curr.begin();
		cout << x << ' ' ; 
		curr.erase( curr.begin() ) ; 
		for( int i = 0 ; i < ans.size() ; i++ ) 
			for( int t =0 ;t < 2 ; t++ ) 
				curr.erase( curr.find( __gcd( ans[i] , x ) ) ); 
		ans.push_back(x);
	}
}
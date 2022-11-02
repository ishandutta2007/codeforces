//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld; 
typedef pair<int,int> pii; 

const int maxN = 200 * 1000 + 10; 

vector<int> a; 
int mark[maxN];
int main() { 
	int n,s; cin >> n >> s; 
	s--; 
	int ttt = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		if( i != s ) { 
			if( x == 0 ) x = n; 
			a.push_back(x); 
		} else if( x ) 
			ttt=1;
	}

	sort( a.begin() , a.end() ); 
	int ans = n-1; 
	int val = 0; 
	for( int i = 0 ; i < n-1 ; i++ ) { 
		if( a[i] == n ) break;
		if( !mark[a[i]] ) { 
			mark[a[i]] = true;
			val++; 
		}
		ans = min( ans , max( a[i] - val , n - 1 - i - 1 ) ); 
	}
	cout << ttt + ans << endl;
		
}
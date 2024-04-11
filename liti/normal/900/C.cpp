//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 100; 
int cnt[maxN];

int main() {
	int mx1, mx2 = mx1 = -1; 
	int n; cin >> n; 

	for(int i = 0; i < n ; i++ ) { 
		int v; cin >> v; 
		if( v > mx1 ) 
			cnt[v]--; 

		if( mx1 > v && v > mx2 ) 
			cnt[mx1]++; 
		if( v > mx1 ) { 
			mx2 = mx1; 
			mx1 = v; 
		} else if( v > mx2 ) { 
			mx2 = v; 
		}
	}
	pii best = { -3 , 0 } ; 
	for( int i = 1 ; i <= n ; i++ ) 
		best = max(best, {cnt[i], -i} ); 
	cout << -best.second << endl;
}
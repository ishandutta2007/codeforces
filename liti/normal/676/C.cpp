//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 100 * 1000 + 10; 
int psum[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,k; cin >> n >> k; 
	int s = 1 , e = n + 1; 
	string t; cin >> t; 
	for( int i =0 ; i < n ; i++ ) 
		psum[i+1] = psum[i] + (t[i] == 'a'); 
	while( e - s > 1 ) { 
		int mid = (s+e)/2; 
		bool canDo = false; 
		for( int i = 0 ; i + mid <= n ; i++ ) 
			if( min( psum[i+mid] - psum[i] , mid - (psum[i+mid]-psum[i])) <= k ) 
				canDo = true; 
		if( canDo ) s = mid; 
		else e = mid; 
	}
	cout << s << endl;
}
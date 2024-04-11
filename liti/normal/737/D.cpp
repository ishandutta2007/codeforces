//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld; 
typedef pair<int,int> pii; 

const int maxN = 4000 + 10; 

int a[maxN]; 
int psum[maxN]; 

int* dp[maxN][maxN][2]; 

int solve( int s , int e , int k , bool t ) { 
	if( dp[s][e][t] == NULL ) { 
		dp[s][e][t] = new int[90]; 
		for( int j = 0 ; j < 90 ; j++ ) 
			dp[s][e][t][j] = -1; 
	}

	auto& v = dp[s][e][t][k]; 
	if( v != -1 ) return v; 
	if( e - s < k ) return v = 0; 
	if( t == 0 ) { 
		v = solve( s + k , e , k , t^1 ) + psum[s+k]-psum[s]; 
		if( e - s > k ) 
			v = max(v, solve( s + k + 1 , e , k + 1 , t ^ 1 ) + psum[s+k+1]-psum[s]); 
	} else { 
		v = solve( s , e - k , k , t^1 ) - (psum[e] - psum[e-k]);
		if( e - s > k ) 
			v = min(v, solve( s , e - k - 1 , k + 1 , t ^ 1 ) - (psum[e]-psum[e-k-1]) ); 
	}
	return v; 
}

int main() { 
	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		psum[i+1] = psum[i] + a[i]; 
	}

	cout << solve( 0 , n , 1 , 0 ) << endl; 
}
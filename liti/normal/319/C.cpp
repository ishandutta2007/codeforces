// In the name of Allah
#include <iostream>
#include <deque>
using namespace std;

const int maxN = 1000*100 + 100; 
typedef long long ll;

int a[maxN], b[maxN];
ll dp[maxN];

ll cross( int i , int j ) { 
	//dp[i] + b[i]*t = dp[j] + b[j]*t =>
	//t = (dp[j] - dp[i])/(b[i]-b[j]) 
	return ( dp[j] - dp[i] + b[i] - b[j] - 1 ) / (b[i]-b[j]) ;
}

deque<int> curr;

int main() { 
	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < n ; i++ ) 
		cin >> b[i];

	int best = 0; // best line yet
	for( int i = 1 ; i < n ; i++ ) { 
		while( !curr.empty() && cross( best, curr[0] ) <= a[i] ) {
			best = curr[0];
			curr.pop_front();
		}

		dp[i] = dp[best] + 1LL*a[i]*b[best];

		curr.push_front( best );
		while( curr.size() >= 2 && cross( i , curr.back() ) <= cross( curr.back() , curr[curr.size()-2] ) ) 
			curr.pop_back();
		curr.pop_front();
		curr.push_back( i ) ;
	}
	cout << dp[n-1] << endl;
}
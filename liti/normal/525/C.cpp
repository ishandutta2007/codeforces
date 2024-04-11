/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*1000 + 10; 

int a[maxN] , b[maxN];

int main() {
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		int num;
		cin >> num; 
		a[num]++; 
	}
	vector<int> ans;
	for( int i = maxN - 1 ; i >= 1 ; i-- ) { 
		while( a[i] + b[i] >= 2 )  {
			for( int j = 0 ; j < 2 ; j++ ) 
				if( b[i] ) b[i]--;
				else a[i]--;
			ans.push_back( i ) ; 
		}
		if( a[i] ) b[i-1]++;
	}
	ll ret = 0; 
	for( int i = 0 ; i + 1 < sz(ans) ; i += 2  )
		ret += ll( ans[i] ) * ans[i+1];
	cout << ret << endl;
}
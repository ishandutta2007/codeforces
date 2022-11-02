/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 500 + 10; 
int w[maxN];
int b[2*maxN];
int last[maxN];
vector<int> a;

int main() { 
	memset( last , -1 , sizeof last ) ;
	int n,m;
	cin >> n >> m;

	for( int i = 0; i < n ;i++ )
		cin >> w[i];
	for( int i = 0 ; i < m ; i++ ){
		cin >> b[i];
		if( last[b[i]] == -1 ) {
			last[b[i]] = i;
			a.push_back( b[i] - 1 ) ;
		}
	}

	int ret = 0;
	for( int i = 0 ; i < m ; i++ ) { 
		int x = b[i] - 1;
		int sum = 0;
		int j;
		for( j = 0 ; j < sz(a) && a[j] != x ; j++ ) 
			sum += w[a[j]];
		for( ; j > 0 ; j-- ) 
			swap( a[j] , a[j-1] ) ;
		ret += sum;
	}
	cout << ret << endl;
}
/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 100 + 10;

ll a[maxN][maxN];

ll b[maxN], c[maxN];
int n,m;
ll k;

bool valid() { 
	for( int i = 0 ; i < n; i++ ) 
		for( int j = 0 ; j < m ; j++ ) 
			if( a[i][j] != (b[i] + c[j]) % k ) 
				return false;
	return true;
}

int main() { 
	cin >> n >> m;
	ll mx = 0;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) {
			cin >> a[i][j];
			mx = max(mx,a[i][j]);
		}

	k = -1;

	ll tmp = -1;
	for( int i = 0 ; i < n ; i++ ) 
		for( int k = 0 ; k < n ; k++ ) {
			vector<int> num;
			for( int j = 0 ; j < m ; j++ ) 
				num.push_back( a[k][j] - a[i][j] ) ; 
			sort(num.begin(),num.end());
			num.resize(unique(num.begin(),num.end())-num.begin());
			if( num.size() > 2 || (num.size() == 2 && (num[0] >= 0 || num[1] < 0) ) ) {
				cout << "NO" << endl;
				return 0;
			}
			if( num.size() == 1 ) continue;
			tmp = -num[0] + num[1];
//			cout << "DBG " << tmp << ' ' << i << ' ' << k << ' ' << num[0] << ' ' << num[1] << endl;
		}
	for( int j = 0 ; j < m ; j++ ) 
		for( int k = 0 ; k < m ; k++ ) {
			vector<int> num;
			for( int i = 0 ; i < n ; i++ ) 
				num.push_back( a[i][k] - a[i][j] ) ; 
			sort(num.begin(),num.end());
			num.resize(unique(num.begin(),num.end())-num.begin());
			if( num.size() > 2 || (num.size() == 2 && (num[0] >= 0 || num[1] < 0) ) ) {
				cout << "NO" << endl;
				return 0;
			}
			if( num.size() == 1 ) continue;
			tmp = -num[0] + num[1];
		}
	k = tmp;
	
//	cout <<k << endl;
	k = max(k,mx+1);

	b[0] = 0;
	c[0] = a[0][0];
	for( int i = 1 ; i < n ; i++ ) 
		b[i] = ( k + a[i][0] - a[0][0] ) % k;
	for( int j = 1 ; j < m ; j++ ) 
		c[j] = ( k + c[0] + a[0][j] - a[0][0] ) % k;
	if( !valid() ) { 
		cout << "NO" <<endl; return 0;
	}

	cout << "YES" << endl;
	cout << k << endl;
	for( int i = 0 ; i < n ; i++ ) 
		cout << b[i] << ' ' ;
	cout << endl;
	for( int i = 0 ; i < m ; i++ ) 
		cout << c[i] << ' ' ;
	cout << endl;
}
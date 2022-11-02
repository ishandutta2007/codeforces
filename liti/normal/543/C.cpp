//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
const int maxN = 20; 
const int maxS = 1<<maxN;
const int maxK = 26 ; 

int dp[maxS];
pair<int,int> v[100];
string a[maxN];
int mat[maxN][maxN];
int tmp[maxK], msk[maxK], mx[maxK];;

int main() { 
	memset( dp , 31 , sizeof dp ) ; 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; 
	cin >> n >> m;
	dp[0] = 0;
	for( int i =0 ; i < n ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) 
			cin >> mat[i][j];
	for( int j = 0 ; j < m ; j++ ) { 
		int en = 0;
		memset( msk , 0 , sizeof msk ) ; 
		memset( tmp , 0 , sizeof tmp ) ; 
		memset( mx , 0 , sizeof mx ) ; 
		for( int i = 0 ; i < n ; i++ ) { 
			v[en++] = { (1<<i) , mat[i][j] } ; 
			msk[a[i][j] -'a'] |= (1<<i);
			tmp[a[i][j] -'a'] += mat[i][j];
			mx[a[i][j]-'a'] = max( mx[a[i][j]-'a'] , mat[i][j] ) ; 
		}
		for( int i = 0 ; i < 26 ; i++ ) if( msk[i] ) 
			v[en++] = { msk[i] , tmp[i] - mx[i] };
		for( int mask = 0 ; mask < (1<<n) ; mask++ ) 
			for( int i = 0 ; i < en ; i++ ) 
				dp[mask|v[i].first] = min( dp[mask|v[i].first] , dp[mask] + v[i].second );
	}
	cout << dp[(1<<n)-1] << endl;
}
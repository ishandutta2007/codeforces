//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
string s; 
const int maxN = 5000 + 10; 
const int maxL = 14;
int val[maxN][maxL];
pair<int,int> tmp[maxN];

inline void make_suffix() { 
	int n = __sz(s);
	for( int i = 0 ; i < n ; i++ ) 
		val[i][0] = s[i];
	for( int k = 1 ; k < maxL ; k++ ) {
		for( int i = 0 ; i < n ; i++ ) 
			tmp[i] = { val[i][k-1] * maxN + val[min(n,i +(1<<(k-1)))][k-1] , i };
		sort( tmp , tmp + n ) ; 
		int cnt = 1; 
		for( int i = 0 ; i < n ; i++ ) 
			if( !i || tmp[i].first == tmp[i-1].first ) 
				val[tmp[i].second][k] = cnt;
			else
				val[tmp[i].second][k] = ++cnt;
	}
}

typedef pair<int,int> SS; // SubStr
inline int get_lcp( int i , int j ) { 
	if( i == j ) return maxN;
	int ret = 0; 
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( val[i][k] == val[j][k] ) { 
			ret += (1<<k);
			i += (1<<k);
			j += (1<<k); 
		}
	return ret;
}
int a[maxN];
bool dp[maxN][maxN];
int st[maxN];
int mn[maxN];
int main() { 
	ios::sync_with_stdio(false);
	cin >> s; 
	int k;  
	cin >> k; 
	make_suffix(); 
	int n = __sz(s);
	for( int i = n - 1 ; i >= 0 ; i-- ) 
		for( int j = i + 1 ; j<= n; j++ ) 
			if( s[i] == s[j-1] ) { 
				if( i + 2 >= j -2 ) dp[i][j] = 1;
				else dp[i][j] = dp[i+2][j-2];
			}
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int x = tmp[i].second;
		int z = tmp[i+1].second;
		a[i] = get_lcp( x , z ) ; 
	}
	for( int i = 0 ; i < n ; i++ ) { 
		int x = tmp[i].second;
		mn[i] = maxN;
		for( int j = i + 1 ; j < n ; j++ ) {
			mn[j] = min(mn[j-1],a[j-1]) ; 
			st[j] = max( st[j] , mn[j] ) ; 
		//	if( mn[j] ) 
		//		cout << j <<   ' ' << mn[j] << endl;
		}
		int ptr = n - 1;
		for( int j = st[i] +1 ; x + j <= n ; j++ ) if( dp[x][x+j] ) { 
			while( mn[ptr] < j ) ptr--;
			int cnt = ptr - i + 1;
		//	cerr << "DBG " << j << ' ' << cnt << endl;
			k -= cnt;
			if( k <= 0 ) { 
				cout << s.substr( x , j ) << endl;
				return 0;
			}
		}
//		cout << s.substr(x) << endl;
//		cout << k << endl;
	}
}
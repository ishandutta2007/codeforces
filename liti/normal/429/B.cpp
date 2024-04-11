#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 1000 + 10; 

int a[4][maxN][maxN],dp[4][maxN][maxN] ;
int n,m;

void calc( int a[maxN][maxN], int dp[maxN][maxN] ) 
{
	dp[0][0] = a[0][0];
	for(int j = 1 ; j < m ;j++ ) 
		dp[0][j] = dp[0][j-1] + a[0][j];
	for(int i = 1 ; i < n ; i++ )
		dp[i][0] = dp[i-1][0] + a[i][0];

	for(int i = 1 ; i < n ; i++ )
		for(int j = 1 ; j < m ; j++ ) 
			dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) + a[i][j];
}

int main()
{
	cin >> n >> m ;

	for(int i = 0 ; i < n ; i++ ) 
		for(int j = 0 ; j < m ; j++ ) 
		{
			cin >> a[0][i][j] ; 
			a[1][i][m-j-1] = a[0][i][j];
			a[2][n-i-1][j] = a[0][i][j];
			a[3][n-i-1][m-j-1] = a[0][i][j];
		}
	
	for(int i =0 ; i < 4 ; i++ ) 
		calc( a[i], dp[i] ) ; 

	int bestAns = 0 ; 
	for(int i = 1 ; i < n-1 ; i++ ) 
		for(int j =1  ; j < m-1 ; j++ )
		{
			int val1 = 0, val2 = 0; 
			val1 = dp[0][i][j-1] + dp[1][i-1][m-j-1] + dp[2][n-i-2][j] + dp[3][n-i-1][m-j-2];
			val2 =  dp[0][i-1][j] + dp[1][i][m-j-2] + dp[2][n-i-1][j-1] + dp[3][n-i-2][m-j-1];
			bestAns = max( bestAns, max( val1, val2 ) ) ; 
		}
	cout << bestAns << endl;
}
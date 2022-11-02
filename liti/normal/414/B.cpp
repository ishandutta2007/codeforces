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

const int maxN = 2000 + 10;
const long long limit = 1000LL*1000LL*1000LL + 7;
long long dp[maxN][maxN];
vector<int> a[maxN];
int main()
{
	int n,k;

	cin >> n >> k; 

	for(int i = 1 ; i <= n ; i++ ) 
		for(int j = i ; j <= n ; j+= i ) 
			a[j].push_back(i);

	for(int i = 1 ; i <= n ; i++ ) 
		dp[0][i] = 1;

	for(int i = 1; i < k ; i++ )
		for(int j = 1; j <= n ; j++ ) 
			for(int z = 0 ; z < SZ( a[j] ) ; z++ ) 
			{
				dp[i][j] += dp[i-1][a[j][z]] ; 
				if( dp[i][j] > limit ) 
					dp[i][j] -= limit;
			}

	long long ans = 0 ; 
	for(int i = 1 ; i <= n  ;i++ ) 
	{
		ans += dp[k-1][i];
		if( ans > limit ) 
			ans -= limit;
	}
	cout << ans << endl;
}
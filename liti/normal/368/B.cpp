#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <deque>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 100*100*10 + 10;

int a[maxN]; 
int d[maxN],dp[maxN];

int main() 
{
	int n,m;
	cin >> n >> m; 

	for(int i =0 ; i < n ;i++ )
	{
		cin >> a[i];
	}

	dp[n-1] = 1;
	d[ a[n-1] ] = 1;
	for(int i = n -  2 ; i >= 0 ; i-- ) 
	{
		dp[i] = dp[i+1];
		if (  d [ a [ i ] ] == 0 ) 
		{
			d[a[i]] = 1;
			dp[i]++;
		}
	}

	for(int i = 0 ; i < m ; i++ )
	{
		int num;
		cin >> num;
		cout << dp[num-1] << endl;
	}
}
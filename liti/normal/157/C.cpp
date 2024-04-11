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

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 2000+ 10;

int dp[maxN][maxN];

int main()
{
	string s,u;
	cin >> s >> u;

	int bestAns = SZ(u);	

	int tmpVal = 0 ; 
	if ( SZ( u ) > SZ( s ) )
	{
		tmpVal = SZ(u) - SZ(s) ; 
		swap( s,u) ; 
	}

	string tmp = "";
	for(int i =0  ; i < SZ(u) ; i++ )
		tmp += "Z";
	s = tmp + s + tmp;
	for(int i = 0 ; i < SZ(s) ; i++ )
	{
		int val =0 ; 
		for(int j = 0 ; i+j < min( SZ(u) + i , SZ(s) ) ; j++ )
		{
			val +=  ( s[i+j] != u[j] ) ;	
			bestAns = min( bestAns, val + SZ(u) - j - 1 ) ; 
		}
	}

	cout << bestAns + tmpVal << endl;
}
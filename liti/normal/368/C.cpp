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

const int maxN = 100*100*10 + 10 ; 
int x[maxN], y[maxN] , z[maxN] ; 

int main() 
{
	string s; 
	cin >> s; 

	int n = SZ( s );
	for(int i = 1 ; i <= n ;i++ )
	{
			x[i] = x[i-1];
			y[i] = y[i-1];
			z[i] = z[i-1];
		if ( s[i-1] == 'x' ) 
			x[i]++;
		else if ( s[i-1] == 'y' ) 
			y[i]++;
		else
			z[i]++;
	}

	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++ )
	{
		int l,r;
		cin >> l >> r; 

		int xx = x[r] - x[l-1], yy = y[r] - y[l-1] , zz = z[r] - z[l-1]; 

		int minVal = min( xx, min( yy, zz ) ) ; 

		int val1 = xx - minVal, val2 = yy - minVal , val3 = zz - minVal ;
		if (  r - l + 1 >= 3 && (  val1 > 1 || val2 > 1 || val3 > 1 ) ) 
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
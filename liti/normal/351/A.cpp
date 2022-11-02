#include <iostream> 
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;


int main() 
{
	int n; 
	cin >> n; 

	int counter = 0 ; 
	int sum = 0;
	for(int i = 0 ; i < 2 * n ;i++  )
	{
		double num; 
		cin >> num;

		double q = round(num * 1000); 
		int x = q;
		x = x%1000;
		sum += x;
		if ( x == 0 ) 
			counter++;
	}

	int m = min( n, ( 2*n ) - counter ) ; 
	int ans = -1;
//	cout << m << ' ' << max( 0, n- counter ) << endl;
	for(int i = max(0, n - counter ) ; i <= m ;i++ )
	{
		int x = 1000*i;
		if ( ans == -1 ||  abs( x - sum ) < ans ) 
			ans = abs(x - sum);
	}
	cout << fixed << setprecision(3) <<  ans / 1000.0 << endl;
}
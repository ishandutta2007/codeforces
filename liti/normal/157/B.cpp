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

const int maxN = 100 + 2; 

double a[maxN];

int main()
{
	int n;
	cin >> n;

	for(int i = 0 ; i < n; i++ )
		cin >> a[i];
	sort( a, a + n ) ; 

	bool turn = false;
	if ( n % 2 == 1 ) 
		turn = true;

	double lS = 0 ;
	double ans = 0 ; 
	for(int i = 0 ; i < n ; i++ )
	{
		double x = M_PI*a[i]*a[i];
		if ( turn ) 
			ans += x - lS; 
		lS = x;
		turn = !turn;
	}
	cout << fixed << setprecision(6) << ans << endl;
}
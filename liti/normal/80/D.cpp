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

void calc()
{
	double a,b;
	cin >> a >> b;
	if ( b == 0 ) 
	{
		cout << 1 << endl;
		return;
	}
	if ( a == 0 ) 
	{
		cout << fixed << setprecision(3) << 1/2.0  << endl;
		return;
	}


	double h1 = a;
	double w = min( a/4.0 , b ) ; 
	double h2 = a - w*4 ; 

	double ans =  ( ( h1 + h2 ) * w )  / 2.0 ;

	cout << fixed  << setprecision(9) <<1/2.0 + (  ans / 2.0 / a / b )  << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>> t;
	for(int i  = 0 ; i < t; i++ )
		calc();
}
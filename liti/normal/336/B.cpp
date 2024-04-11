#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist = 0;
double div =0;
long long x;
long long m; 
long long r;
int main() 
{
	cin >> m >> r; 

	if ( m == 1 )
	{
		cout << 2 * r << endl;
		return 0;
	}
	x =  (m-2) * (m-1) ;

//	cout <<dist << ' ' <<  x << endl;
	dist += x;
	dist += 4 ; 
	dist += 2* ( max(m - 2,0LL) + .5 ) * sqrt(2.);
	dist = dist / m; 
//	cout << x << endl;
	for(long long i = 1 ; i < m ; i++ ) 
	{
	//	cout << (m-i - 1 ) * 2 << endl;
	//	x -= ( m - i - 1 ) * 2 ; 
		x += ( 2*i - m  ) * 2;
		if ( i != m - 1 ) 
		{
			dist += ( x + 6 + 2 * ( max(m-3,0LL) + 1 ) * sqrt(2.) ) / m;
		}	
		else
		{
			dist += ( x + 4 + 2 *(max(m-2,0LL) + .5 ) * sqrt(2.) ) / m;
		}
	//	x += ( i - 1 ) * 2 ;

//		cout << x << endl;
	}

//	cout << dist << endl;
//	cout <<fixed << setprecision(10) << m * n * sqrt( 2 )  << endl; 
//	div = m;
	cout << fixed << setprecision(10) << ( dist / m )   * r  << endl;
}
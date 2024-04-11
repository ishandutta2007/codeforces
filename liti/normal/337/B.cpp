#include <iostream>
#include <cmath>

using namespace std;

void ans( int x,int  y )
{

	int m = max(x,y);
	for(int i = 2; i <= m ; i++ )
	{
		if ( x == 0 && y == 0 ) 
			break;
		if ( x%i == 0 && y%i == 0 ) 
		{
//			cout  << x <<  y <<i << endl;
			x = x /  i ; 
			y = y / i ;

			i--; 
		}
	}
	cout << x << '/' << y << endl;
}
int main() 
{
	int a,b,c,d; 
	cin >> a >> b >> c >> d; 

	
	int x1,x2,y1,y2;

	x1 = b*c;
    y1 = b*c - a*d;
	x2 = a*d;
	y2 = a*d - b*c;
	
	if ( y1 >= 0 ) 
	{
		ans( y1, x1 )  ; 
	}
	else
	{
		ans( y2, x2 ) ; 
	}
}
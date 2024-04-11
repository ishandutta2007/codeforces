#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	long double a,b,c,d,ans,r,s,t;
	cin >> a >> b >> c >> d;
	r = ( b - a ) ; 
	s = r * c ;
	d = b * d;
	a = a * d;
	s = s * b;


	ans= a / (a+ s );
	
	


	cout << setprecision(9) << fixed << ans << endl;
}
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

double getDist( double x1, double y1, double x2, double y2 ) 
{
	double x = (x1 - x2) ; 
	double y = (y1 - y2) ; 

	return sqrt( x*x + y*y ) ; 
}

int main()
{
	int n, k;
	cin >> n >> k; 

	double lastX,lastY; 
	cin >> lastX >> lastY;

	double tDist = 0;
	for(int i = 1 ; i <n ;i++ )
	{
		double x,y;
		cin >> x >> y;

		tDist += getDist( lastX, lastY, x, y );
		lastX = x; 
		lastY = y;
	}


	tDist *= k ; 

	tDist /= 50.f;

	cout << fixed << setprecision(7) <<  tDist << endl;
}
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double r,x1,y1,x2,y2,dist;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	cout << ceil(dist/(r*2));
}
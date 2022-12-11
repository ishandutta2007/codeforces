#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#include <iomanip>

#define MAXN 4
#define EPS 0.0001
#define PI 4 * (atan(1))

using namespace std;

typedef pair<double, double> pii;
pii coor[MAXN];
double dist[3];
double angle[3];
double fangle;
double R;
double S;
double sides;
double ans;

double fdist(pii a, pii b)
{
	return (sqrt(((b.first - a.first)*(b.first - a.first)) + ((b.second - a.second)*(b.second - a.second))));
}
double area(double a, double b, double c)
{
	double s = (a + b + c)/2;
	return sqrt((s)*(s - a)*(s - b)*(s - c));
}
double fgcd(double x, double y)
{
    while (fabs(x) > EPS && fabs(y) > EPS)
    {
        if (x > y)
        {
        	x -= floor(x / y) * y;
        }
        else
        {
        	y -= floor(y / x) * x;
        }
    }
    return x + y;
}



int main()
{
    ios_base::sync_with_stdio(false);
	if (fopen("cf1c.in", "r"))
	{	
		freopen ("cf1c.in", "r", stdin);
		freopen ("cf1c.out", "w", stdout);
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> coor[i].first >> coor[i].second;
	}
	dist[0] = fdist(coor[0], coor[1]);
	dist[1] = fdist(coor[1], coor[2]);
	dist[2] = fdist(coor[2], coor[0]);
	angle[0] = acos((dist[2]*dist[2] + dist[1] * dist[1] - dist[0]*dist[0])/(2 * dist[2] * dist[1]));
	angle[1] = acos((dist[2]*dist[2] + dist[0] * dist[0] - dist[1]*dist[1])/(2 * dist[0] * dist[2]));
	angle[2] = acos((dist[1]*dist[1] + dist[0] * dist[0] - dist[2]*dist[2])/(2 * dist[0] * dist[1]));
	//
	S = area(dist[0], dist[1], dist[2]);
//	cerr << S << endl;
	R = (dist[0]*dist[1]* dist[2])/(4.0000000000*S);
//	cerr << R << endl;
	fangle = fgcd(fgcd(angle[0], angle[1]), angle[2]);
	sides = PI/fangle;
//	cerr << sides << ' ' << R << endl;
	ans = sides * 0.50000000000 * sin(2.0000000000 * PI/sides) * R * R;
//	cerr << fangle << endl;
	printf("%.6f", ans);
	return 0;
	//number of tiranlges (1/
	//find gcd to find number of edges
}
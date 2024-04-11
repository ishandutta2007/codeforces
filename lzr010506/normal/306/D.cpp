#include <bits/stdc++.h>
using namespace std;
int n; 
struct Point
{
	double x,y;
	Point operator +(const Point &a) const
    { 
    	return (Point){x + a.x, y + a.y}; 
    }
  	Point operator -(const Point &a) const
    { 
    	return (Point){x - a.x, y - a.y}; 
    }
  	Point operator *(const double &a) const
    { 
    	return (Point){x * a, y * a}; 
    }
  	Point operator /(const double &a) const
    { 
    	return (Point){x / a, y / a}; 
    }
} P[200];

int main()
{
	scanf("%d",&n);
	if (n < 5) {printf("No solution\n");return 0;}
	double len = 300, dlt = 0.01;
	Point w;
	for (int i = 1; i < n; i ++)
	{
		w = (Point) { cos(2 * M_PI / n * (i - 1)), sin(2 * M_PI / n * (i - 1))};
		P[i] = P[i - 1] + w * len;
		len += dlt;
	}
	w = (Point) { cos(2 * M_PI / n * (n - 1)), sin(2 * M_PI / n * (n - 1)) };
	P[n] = P[n - 1] - w * (P[n - 1].y / w.y);
	for (int i = 1; i <= n; i ++) 
		printf("%.3lf %.3lf\n",P[i].x,P[i].y);
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#else
#endif
}
struct Point 
{
	int x, y;
	Point(){}
	Point(int X, int Y) { x = X; y = Y; }
	bool operator <( Point b ) { return x < b.x || ( x == b.x && y < b.y ); }
	Point operator -( Point b ) { return Point( x - b.x, y - b.y ); } 
	Point operator +( Point b ) { return Point( x + b.x, y + b.y ); } 
	int operator *( Point b ) { return x * b.y - y * b.x; } 
	Point operator *( int b ) { return Point( x * b, y * b ); } 
	int sqrdist( ) { return x * x + y * y; } 
	double dist( ) { return sqrt( (double)sqrdist( ) ); }
	void scan( ) { scanf ( "%d%d\n", &x, &y ); }
};
Point a[100009];
int main()
{
	prepare ();
int n;
cin>>n;
int i;
for (i=0; i<n; i++)
a[i].scan();
int c=a[0].x, d=a[0].y, e=c, f=d;
for (i=1; i<n; i++)
{
	if (a[i].x<c)
		c=a[i].x;
	if (a[i].x>e)
		e=a[i].x;
	if (a[i].y<d)
		d=a[i].y;
	if (a[i].y>f)
		f=a[i].y;
}
for (i=0; i<n; i++)
{
	a[i].x-=(c-1);
	a[i].y-=(d-1);
}
e-=(c-1);
f-=(d-1);

int q=a[0].y-a[0].x, w=a[0].y+a[0].x, u=q, r=w;
for (i=1; i<n; i++)
{
if (a[i].y-a[i].x<q)
q=a[i].y-a[i].x;
if (a[i].y+a[i].x<w)
w=a[i].y+a[i].x;
if (a[i].y-a[i].x>u)
u=a[i].y-a[i].x;
if (a[i].y+a[i].x>r)
r=a[i].y+a[i].x;
}
u++;
r++;
q--;
w--;
cout<<(u-w+r-q);
return 0;
}
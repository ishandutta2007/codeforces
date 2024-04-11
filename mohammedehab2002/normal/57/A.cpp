#include <iostream>
#include <algorithm>
using namespace std;
int solve (int n,int x,int y)
{
	if (y==0)
	return x;
	if (x==n)
	return n+y;
	if (y==n)
	return 3*n-x;
	return 4*n-y;
}
int main()
{
	int n,x1,y1,x2,y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	x1=solve(n,x1,y1);
	x2=solve(n,x2,y2);
	if (x1>x2)
	swap (x1,x2);
	cout << min(x2-x1,4*n-(x2-x1));
}
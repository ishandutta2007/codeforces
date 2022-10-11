#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double dist(int a,int b,int c,int d)
{
	return sqrt(pow(a-c,2)+pow(b-d,2));
}
int main()
{
	double ans=1e9;
	int a,b,n;
	cin >> a >> b >> n;
	for (int i=0;i<n;i++)
	{
		int x,y,v;
		cin >> x >> y >> v;
		ans=min(ans,(dist(a,b,x,y)/v));
	}
	cout << setprecision(9) << fixed << ans;
}
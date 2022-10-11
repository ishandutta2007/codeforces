#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,i,maxx,maxy;
	cin >> n;
	int c1[n],c2[n];
	for (i=0;i<n;i++)
	cin >> c1[i] >> c2[i];
	sort (c1,c1+n);
	sort (c2,c2+n);
	maxx=c1[n-1]-c1[0];
	maxy=c2[n-1]-c2[0];
	cout << max(maxx,maxy)*max(maxx,maxy);
}
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[8],i,a1,a2,a3;
	for (i=0;i<8;i++)
	cin >> a[i];
	a1=a[1]*a[2]/a[6];
	a2=a[3]*a[4];
	a3=a[5]/a[7];
	cout << min(min(a1,a2),a3)/a[0];
}
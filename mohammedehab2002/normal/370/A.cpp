#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int r1,r2,c1,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1==r2 || c1==c2)
    cout << "1 ";
    else
    cout << "2 ";
    if ((r1+c1)%2==(r2+c2)%2)
    {
    	if (r1+c1==r2+c2 || r1-c1==r2-c2)
    	cout << "1 ";
    	else
    	cout << "2 ";
	}
	else
	cout << "0 ";
	cout << max(abs(r1-r2),abs(c1-c2));
}
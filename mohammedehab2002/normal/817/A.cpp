#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int x1,y1,x2,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if ((x2-x1)%x)
    {
    	cout << "NO";
    	return 0;
	}
    y1+=(abs(x2-x1)/x)*y;
    if ((y2-y1)%(2*y)==0)
    cout << "YES";
    else
    cout << "NO";
}
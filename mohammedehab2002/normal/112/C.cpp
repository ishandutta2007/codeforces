#include <iostream>
using namespace std;
int main()
{
	long long n,x,y;
	cin >> n >> x >> y;
	long long z=y-n+1;
	if (z*z+n-1>=x && z>0)
	{
	    cout << z << endl;
	    n--;
	    while (n--)
	    cout << 1 << endl;
	}
	else
	cout << -1;
}
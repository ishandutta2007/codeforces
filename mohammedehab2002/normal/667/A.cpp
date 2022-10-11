#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	double v=0.25*3.14159265359*a*a*b,v2=0.25*3.14159265359*a*a*d;
	if (v2>=c)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl << (double)v/(c-v2);
}
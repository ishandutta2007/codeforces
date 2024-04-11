#include <iostream>
using namespace std;
int main()
{
	int n,a,b,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		if (a!=b)
		{
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";
}
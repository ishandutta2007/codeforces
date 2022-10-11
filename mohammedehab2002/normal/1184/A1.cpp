#include <iostream>
using namespace std;
int main()
{
	long long r;
	cin >> r;
	if (r<5 || r%2==0)
	{
		cout << "NO";
		return 0;
	}
	cout << "1 " << (r-3)/2;
}
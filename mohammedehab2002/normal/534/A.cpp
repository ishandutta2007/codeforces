#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	if (n==1)
	cout << 1 << endl << 1;
	else if (n==2)
	cout << 1 << endl <<  1;
	else if (n==3)
	cout << 2 << endl << 1 << " " << 3;
	else if (n==4)
	cout << 4 << endl << "3 1 4 2";
	else
	{
		cout << n << endl;
		for (i=0;i<n;i+=2)
		cout << i+1 << " ";
		for (i=1;i<n;i+=2)
		cout << i+1 << " ";
	}
}
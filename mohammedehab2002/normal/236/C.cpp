#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if (n%6==0)
	n--;
	if (n<3)
	cout << n;
	else if (n%2)
	cout << n*(n-1)*(n-2);
	else
	cout << n*(n-1)*(n-3);
}
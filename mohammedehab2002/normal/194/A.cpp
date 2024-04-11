#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	if (n-(k-(n*2))<0)
	cout << 0;
	else
	cout << n-(k-(n*2));
}
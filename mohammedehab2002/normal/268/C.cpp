#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	if (n>m)
	swap(n,m);
	cout << n+1 << endl;
	m=0;
	while (n>=0)
	{
		cout << n << " " << m << endl;
		m++;
		n--;
	}
}
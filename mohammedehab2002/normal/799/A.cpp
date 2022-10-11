#include <iostream>
using namespace std;
int main()
{
	int n,t,k,d;
	cin >> n >> t >> k >> d;
	if (d+t<n/k*t+(n%k!=0)*t)
	cout << "YES";
	else
	cout << "NO";
}
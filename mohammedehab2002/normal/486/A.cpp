#include <iostream>
using namespace std;
int main()
{
	long long n,ans=0;
	cin >> n;
	if (n%2)
	cout << -1*(n/2+1);
	else
	cout << n/2;
}
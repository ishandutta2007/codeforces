#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long i=1,len=1;
	for (;i+len-1<n;i+=len,len++)
	{
	}
	cout << n-i+1;
}
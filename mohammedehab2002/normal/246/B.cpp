#include <iostream>
using namespace std;
int main()
{
	int n,i,a,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		ans+=a;
	}
	cout << n-(bool)(ans%n);
}
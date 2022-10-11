#include <iostream>
using namespace std;
int main()
{
	int n,i=1,ans=1;
	cin >> n;
	while (n-ans>=0)
	{
		ans+=i;
		n-=ans;
		i++;
	}
	cout << i-1;
}
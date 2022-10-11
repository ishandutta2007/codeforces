#include <iostream>
using namespace std;
int main()
{
	int n,ans=0;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		ans=(ans+(a-1)%2)%2;
		if (ans)
		cout << 1 << endl;
		else
		cout << 2 << endl;
	}
}
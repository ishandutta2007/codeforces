#include <iostream>
using namespace std;
int main()
{
	int n,b,d,s=0,ans=0;
	cin >> n >> b >> d;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		if (a>b)
		continue;
		s+=a;
		if (s>d)
		ans++,s=0;
	}
	cout << ans;
}
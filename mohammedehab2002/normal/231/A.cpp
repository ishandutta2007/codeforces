#include <iostream>
using namespace std;
int main()
{
	int n,a1,a2,a3,i,test=0,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a1 >> a2 >> a3;
		if (a1==1)
		test++;
		if (a2==1)
		test++;
		if (a3==1)
		test++;
		if (test>1)
		ans++;
		test=0;
	}
	cout << ans;
}
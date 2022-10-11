#include <iostream>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int n,i,n1,n2,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> n1 >> n2;
		if (abs(n1-n2)>=2)
		ans++;
	}
	cout << ans;
}
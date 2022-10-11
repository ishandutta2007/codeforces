#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i,y,w,ans=0;
	cin >> y >> w;
	int d=max(y,w);
	for (i=d;i<=6;i++)
	{
		ans++;
	}
	if (ans==1 || ans==5)
	cout << ans << "/6";
	else if (ans==2)
	cout << "1/3";
	else if (ans==3)
	cout << "1/2";
	else if (ans==4)
	cout << "2/3";
	else
	cout << "1/1";
}
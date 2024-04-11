#include <iostream>
#include <assert.h>
using namespace std;
bool query(int x,int y)
{
	cout << "? " << x << ' ' << y << endl;
	string s;
	cin >> s;
	assert(s!="e");
	return (s=="y");
}
int main()
{
	cout.flush();
	while (1)
	{
		string s;
		cin >> s;
		if (s!="start")
		break;
		if (!query(0,1))
		{
			cout << "! 1" << endl;
			continue;
		}
		int i=0;
		while (query((1<<i),(1<<(i+1))))
		i++;
		int ans=(1<<i);
		while (--i>=0)
		{
			if (query(ans,ans+(1<<i)))
			ans+=(1<<i);
		}
		cout << "! " << ans+1 << endl;
	}
}
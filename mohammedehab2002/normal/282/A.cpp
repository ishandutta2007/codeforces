#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,ans=0;
	cin >> n;
	string s;
	for (i=0;i<n;i++)
	{
		cin >> s;
		if (s[1]=='+')
		ans++;
		else ans--;
	}
	cout << ans;
}
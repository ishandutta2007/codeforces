#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='0')
		{
			cout << ans;
			ans=0;
			continue;
		}
		ans++;
	}
	cout << ans;
}
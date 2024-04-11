#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,ans=1;
	cin >> n;
	string s[n];
	for (i=0;i<n;i++)
	cin >> s[i];
	for (i=1;i<n;i++)
	{
		if (s[i]!=s[(i-1)])
		ans++;
	}
	cout << ans;
}
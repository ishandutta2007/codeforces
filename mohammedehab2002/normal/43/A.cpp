#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,maxi=0;
	cin >> n;
	string s[n],ans;
	for (i=0;i<n;i++)
	cin >> s[i];
	for (i=0;i<n;i++)
	{
		if (count(s,s+n,s[i])>maxi)
		{
			maxi=count(s,s+n,s[i]);
			ans=s[i];
		}
	}
	cout << ans;
}
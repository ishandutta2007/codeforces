#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,ans=0;
	string s;
	cin >> n >> s;
	if (n>26)
	{
		cout << -1;
		return 0;
	}
	sort(s.begin(),s.end());
	for (i=1;i<n;i++)
	{
		if (s[i]==s[i-1])
		ans++;
	}
	cout << ans;
}
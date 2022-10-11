#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	char c;
	int l,n,i,a,ans=0;
	string s;
	cin >> l >> n >> s;
	for (i=0;i<l-1;i++)
	{
		if (s[i]=='.' && s[i+1]=='.')
		ans++;
	}
	for (i=0;i<n;i++)
	{
		cin >> a >> c;
		if (s[a-1]=='.' && s[a]=='.')
		ans--;
		if (s[a-1]=='.' && s[a-2]=='.')
		ans--;
		s[a-1]=c;
		if (s[a-1]=='.' && s[a]=='.')
		ans++;
		if (s[a-1]=='.' && s[a-2]=='.')
		ans++;
		cout << ans << endl;
	}
}
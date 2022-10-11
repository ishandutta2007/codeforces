#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m,i,x,ans=0;
	cin >> n >> m;
	string s[n],a;
	for (i=0;i<n;i++)
	cin >> s[i];
	for (i=0;i<n-1;i++)
	{
		for (x=0;x<m-1;x++)
		{
			a+=s[i][x];
			a+=s[i+1][x];
			a+=s[i][x+1];
			a+=s[i+1][x+1];
			if (a.find('f')!=string::npos && a.find('a')!=string::npos && a.find('c')!=string::npos && a.find('e')!=string::npos)
			ans++;
			a.clear();
		}
	}
	cout << ans;
}
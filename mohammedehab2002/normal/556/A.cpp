#include <iostream>
#include <string.h>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int n,i,ans=0;
	string s;
	cin >> n >> s;
	for (i=0;i<n;i++)
	{
		if (s[i]=='0')
		ans++;
		else
		ans--;
	}
	cout << abs(ans);
}
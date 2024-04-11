#include <iostream>
#include <string.h>
using namespace std;
int abs(int x)
{
	return (x>0)? x:x*-1;
}
int main()
{
	int n,i,c1=0,c2=0,ans,c=0;
	string s;
	cin >> n >> s;
	for (i=0;i<n;i++)
	{
		if (s[i]=='x')
		c1++;
		else
		c2++;
	}
	ans=(abs(c2-c1))/2;
	cout << ans << endl;
	for (i=0;i<n && c<ans;i++)
	{
		if (s[i]=='x' && c1>c2)
		{
			s[i]='X';
			c++;
		}
		else if (s[i]=='X' && c1<c2)
		{
			s[i]='x';
			c++;
		}
	}
	cout << s;
}
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,i,x,ans=0;
	string s;
	cin >> n >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]==s[i+1])
		{
			ans++;
			for (x=i+1;x<s.size()-1;x++)
			s[x]=s[x+1];
			i--;
			s.resize(s.size()-1);
		}
	}
	cout << ans;
}
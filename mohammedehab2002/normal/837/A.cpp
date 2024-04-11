#include <iostream>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n;
	getchar();
	getline(cin,s);
	s+=' ';
	int c=0,ans=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]==' ')
		{
			ans=max(ans,c);
			c=0;
		}
		if (s[i]>='A' && s[i]<='Z')
		c++;
	}
	cout << ans;
}
#include <iostream>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i=1;i<s.size();i++)
	{
		if (s[i]!=s[i-1])
		{
			cout << "YES\n" << s[i-1] << s[i];
			return 0;
		}
	}
	cout << "NO";
}
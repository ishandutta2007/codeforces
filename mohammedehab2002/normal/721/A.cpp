#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int n,ans=0;
	string s;
	cin >> n >> s;
	int co=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='W')
		{
			if (co)
			{
				ans++;
				v.push_back(co);
			}
			co=0;
		}
		else
		co++;
	}
	if (co)
	{
		ans++;
		v.push_back(co);
	}
	cout << ans << endl;
	for (int i=0;i<v.size();i++)
	cout << v[i] << ' ';
}
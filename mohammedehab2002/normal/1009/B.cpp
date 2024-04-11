#include <iostream>
#include <set>
using namespace std;
set<int> s[3];
int main()
{
	string t;
	cin >> t;
	for (int i=0;i<t.size();i++)
	s[t[i]-'0'].insert(i);
	for (int i=0;i<t.size();i++)
	{
		for (int x=0;x<3;x++)
		{
			if (s[x].empty())
			continue;
			auto it=s[x].begin();
			if (x==1 || s[2-x].empty())
			{
				t[i]=x+'0';
				s[x].erase(it);
				break;
			}
			auto it2=s[2-x].begin();
			if (*it<*it2)
			{
				t[i]=x+'0';
				s[x].erase(it);
				break;
			}
		}
	}
	cout << t;
}
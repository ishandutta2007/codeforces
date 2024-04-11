#include <iostream>
#include <set>
#include <map>
using namespace std;
map <int,pair<bool,bool> > m;
set <int> s;
int main()
{
	int n,a;
	cin >> n;
	cin >> a;
	s.insert(a);
	for (int i=1;i<n;i++)
	{
		cin >> a;
		int s1=-1,s2=-1;
		if (s.upper_bound(a)!=s.end())
		s1=*(s.upper_bound(a));
		if (s.upper_bound(a)!=s.begin())
		s2=*(--s.upper_bound(a));
		if (s1==-1)
		{
			cout << s2 << ' ';
			m[s2].first=1;
		}
		else if (s2==-1)
		{
			cout << s1 << ' ';
			m[s1].second=1;
		}
		else
		{
			if (m[s2].first==1)
			{
				cout << s1 << ' ';
				m[s1].second=1;
			}
			else
			{
				cout << s2 << ' ';
				m[s2].first=1;
			}
		}
		s.insert(a);
	}
}
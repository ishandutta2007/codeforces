#include <iostream>
#include <string.h>
#include <deque>
#include <map>
using namespace std;
deque <string> d;
map <string,bool> m;
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		d.push_front(s);
	}
	for (int i=0;i<n;i++)
	{
		if (!m[d[i]])
		{
			cout << d[i] << endl;
			m[d[i]]=true;
		}
	}
}
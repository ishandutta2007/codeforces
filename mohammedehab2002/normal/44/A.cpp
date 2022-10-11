#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int main()
{
	pair<string,string> s;
	set <pair<string,string> > t;
	int n,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> s.first >> s.second;
		t.insert(s);
	}
	cout << t.size();
}
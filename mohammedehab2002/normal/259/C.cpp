#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (count(s.begin(),s.end(),'0')==0)
	{
		s.erase(s.begin());
		cout << s;
		return 0;
	}
	s.erase(find(s.begin(),s.end(),'0'));
	cout << s;
}
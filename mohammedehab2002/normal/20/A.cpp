#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int i;
	vector <char> v;
	vector <char> :: iterator it;
	string s;
	cin >> s;
	if (count(s.begin(),s.end(),'/')==s.size())
	{
		cout << '/';
		return 0;
	}
	for (i=0;i<s.size();i++)
	v.push_back(s[i]);
	for (it=v.begin();it!=v.end();it++)
	{
		if (*it=='/')
		{
			it++;
			if (*it=='/')
			{
				it--;
				v.erase(it);
			}
			it--;
		}
	}
	if (v.back()=='/')
	v.pop_back();
	for (it=v.begin();it!=v.end();it++)
	cout << *it;
}
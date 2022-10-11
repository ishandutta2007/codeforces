#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return a.size()<b.size();
}
int main()
{
	int n,k;
	cin >> n >> k;
	string s[n],ans;
	for (int i=0;i<n;i++)
	cin >> s[i];
	cin >> ans;
	sort(s,s+n,cmp);
	int i;
	for (i=0;i<n;i++)
	{
		if (ans.size()==s[i].size())
		break;
	}
	int best=i+(i/k)*5+1;
	for (;i<n;i++)
	{
		if (s[i].size()>ans.size())
		break;
	}
	int worst=i+((i-1)/k)*5;
	cout << best << ' ' << worst << endl;
}
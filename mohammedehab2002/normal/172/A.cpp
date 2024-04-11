#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,ans=0,size;
	cin >> n;
	string s[n],t="";
	for (i=0;i<n;i++)
	cin >> s[i];
	size=s[0].size();
	again: size--;
	t="";
	for (i=0;i<n;i++)
	t+=s[i][0];
	if (size>1)
	{
		if (count(t.begin(),t.end(),t[0])==n)
		{
			ans++;
			for (i=0;i<n;i++)
			s[i].erase(s[i].begin());
			goto again;
		}
	}
	if (size==1)
	{
		t="";
		for (i=0;i<n;i++)
		t+=s[i][0];
	}
	if (count(t.begin(),t.end(),t[0])==n)
	ans++;
	cout << ans;
}
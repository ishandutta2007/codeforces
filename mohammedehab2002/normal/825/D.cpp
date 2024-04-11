#include <iostream>
#include <algorithm>
using namespace std;
int cnt[27][2],x;
void go()
{
	while (x<26 && cnt[x][0]>=0)
	x++;
	if (x==26)
	{
		x=0;
		for (int i=0;i<26;i++)
		cnt[i][0]-=cnt[i][1];
		go();
	}
}
int main()
{
	string s,t;
	cin >> s >> t;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]!='?')
		cnt[s[i]-'a'][0]++;
	}
	for (int i=0;i<t.size();i++)
	cnt[t[i]-'a'][1]++;
	go();
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='?')
		{
			s[i]=x+'a';
			cnt[x][0]++;
			go();
		}
	}
	cout << s;
}
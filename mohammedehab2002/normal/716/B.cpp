#include <iostream>
#include <string.h>
#include <set>
using namespace std;
set<char> st;
int cnt[26];
int main()
{
	string s;
	cin >> s;
	if (s.size()<26)
	{
		cout << -1;
		return 0;
	}
	int c=0;
	for (int i=0;i<25;i++)
	{
		if (s[i]!='?')
		st.insert(s[i]),cnt[s[i]-'A']++;
		else
		c++;
	}
	bool b=0;
	for (int i=25;i<s.size();i++)
	{
		if (s[i]!='?')
		st.insert(s[i]),cnt[s[i]-'A']++;
		else
		c++;
		if (st.size()+c==26)
		{
			char cur='A';
			for (int x=i-25;x<=i;x++)
			{
				if (s[x]=='?')
				{
					while (st.find(cur)!=st.end())
					cur++;
					s[x]=cur;
					cur++;
				}
			}
			b=1;
			break;
		}
		if (s[i-25]!='?')
		{
			cnt[s[i-25]-'A']--;
			if (cnt[s[i-25]-'A']==0)
			st.erase(st.find(s[i-25]));
		}
		else
		c--;
	}
	if (b)
	{
		for (int i=0;i<s.size();i++)
		{
			if (s[i]=='?')
			cout << 'A';
			else
			cout << s[i];
		}
	}
	else
	cout << -1;
}
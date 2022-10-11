#include <iostream>
#include <map>
using namespace std;
map <int,string> b;
int dcnt(long long n)
{
	int ans=0;
	while (n)
	{
		n/=7;
		ans++;
	}
	return ans;
}
string change(string s,int pos)
{
	s[pos]++;
	if (s[pos]=='7')
	{
		s[pos]='0';
		s=change(s,pos-1);
	}
	return s;
}
int func(string s,int m)
{
	int ret=m;
	for (long long i=0;i<m;i++)
	{
		bool c=false;
		map <char,int> cnt;
		string s2=b[i];
		for (int x=0;x<s.size();x++)
		{
			cnt[s[x]]++;
			if (cnt[s[x]]==2)
			c=true;
		}
		for (int x=0;x<s2.size();x++)
		{
			cnt[s2[x]]++;
			if (cnt[s2[x]]==2)
			c=true;
		}
		if (c)
		ret--;
	}
	return ret;
}
int main()
{
	long long n,m,ans=0;
	cin >> n >> m;
	int c=dcnt(n-1),c2=dcnt(m-1);
	if (!c)
	c=1;
	if (!c2)
	c2=1;
	if (c+c2>7)
	{
		cout << 0;
		return 0;
	}
	string s(c,'0'),s2(c2,'0');
	for (int i=0;i<m;i++)
	{
		b[i]=s2;
		s2=change(s2,c2-1);
	}
	for (int i=0;i<n;i++)
	{
		ans+=func(s,m);
		s=change(s,c-1);
	}
	cout << ans;
}
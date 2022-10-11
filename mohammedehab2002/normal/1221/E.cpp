#include <bits/stdc++.h>
using namespace std;
int a,b;
bool useful(int x)
{
	return x>=b;
}
bool ok(int x)
{
	return ((x>=a || x<b) && x<2*b);
}
int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		string s;
		cin >> a >> b >> s;
		s+="X";
		int cnt=0,l=-1,dec=-1;
		bool win=0;
		for (int i=0;i<s.size();i++)
		{
			if (s[i]=='X')
			{
				int cur=i-l-1;
				l=i;
				if (!useful(cur))
				continue;
				if (cur<a || cur>a+4*b-2)
				win=1;
				else if (cur>=2*b)
				{
					if (dec==-1)
					dec=cur;
					else
					win=1;
				}
				else
				cnt^=1;
			}
		}
		if (win)
		{
			puts("NO");
			continue;
		}
		if (dec==-1)
		{
			puts(cnt? "YES":"NO");
			continue;
		}
		bool sec=1;
		for (int i=0;i<=dec-a;i++)
		{
			if (ok(i) && ok(dec-i-a) && !(cnt^useful(i)^useful(dec-i-a)))
			sec=0;
		}
		puts(sec? "NO":"YES");
	}
}
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int next[1010];

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		string s;
		cin>>s;
		int pre=s.length(),tot=0;
		for (int i=s.length()-1;i>=0;--i)
		{
			if (s[i]==':')
			{
				next[i]=pre;
				pre=i;
				++tot;
			}
		}
		for (int i=pre;i<4;++i)
			putchar('0');
		for (int i=0;i<s.length();++i)
		{
			if (s[i]==':')
				if (s[i+1]==':')
				{
					while (++tot<=8) printf(":0000");
				}
				else
				{
					putchar(':');
					for (int j=next[i]-i;j<=4;++j) putchar('0');
				}
			else
				putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<string> v;
int main()
{
	int n;
	cin >> n;
	string last="0";
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if (s.size()<last.size())
		{
			printf("NO");
			return 0;
		}
		if (s.size()>last.size())
		{
			for (int i=0;i<s.size();i++)
			{
				if (s[i]=='?')
				s[i]='0'+!i;
			}
		}
		else
		{
			bool g=0;
			for (int i=0;i<s.size();i++)
			{
				if (s[i]!='?' && s[i]!=last[i])
				{
					for (int j=i+1;j<s.size();j++)
					{
						if (s[j]=='?')
						s[j]='0';
					}
					if (s[i]>last[i])
					g=1;
					break;
				}
			}
			if (!g)
			{
				for (int i=s.size()-1;i>=0;i--)
				{
					if (s[i]=='?')
					{
						if (last[i]=='9')
						s[i]='0';
						else
						{
							s[i]=last[i]+1;
							break;
						}
					}
				}
			}
			for (int i=0;i<s.size();i++)
			{
				if (s[i]=='?')
				s[i]=last[i];
			}
		}
		if (s.size()==last.size() && s<=last)
		{
			printf("NO");
			return 0;
		}
		last=s;
		v.push_back(s);
	}
	printf("YES\n");
	for (string s:v)
	cout << s << endl;
}
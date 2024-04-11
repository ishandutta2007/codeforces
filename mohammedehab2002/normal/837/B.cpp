#include <iostream>
#include <string.h>
#include <set>
using namespace std;
string s[105];
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	cin >> s[i];
	bool ok=0;
	if (n%3==0)
	{
		bool b=1;
		set<char> st;
		for (int i=0;i<n;i+=n/3)
		{
			if (st.find(s[i][0])!=st.end())
			b=0;
			st.insert(s[i][0]);
			for (int x=i;x<i+n/3;x++)
			{
				for (int j=0;j<m;j++)
				{
					if (s[x][j]!=s[i][0])
					b=0;
				}
			}
		}
		ok|=b;
	}
	if (m%3==0)
	{
		bool b=1;
		set<char> st;
		for (int i=0;i<m;i+=m/3)
		{
			if (st.find(s[0][i])!=st.end())
			b=0;
			st.insert(s[0][i]);
			for (int x=i;x<i+m/3;x++)
			{
				for (int j=0;j<n;j++)
				{
					if (s[j][x]!=s[0][i])
					b=0;
				}
			}
		}
		ok|=b;
	}
	if (ok)
	cout << "YES";
	else
	cout << "NO";
}
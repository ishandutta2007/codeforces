#include <bits/stdc++.h>
using namespace std;
string a="abacaba";
bool check(string s)
{
	int cnt=0;
	for (int i=0;i<(int)s.size()-6;i++)
	cnt+=(s.substr(i,7)==a);
	return (cnt==1);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s,ans="No";
		cin >> n >> s;
		for (int i=0;i<n-6;i++)
		{
			string tmp=s;
			for (int j=0;j<n;j++)
			{
				if (tmp[j]=='?')
				{
					if (j>=i && j-i<7)
					tmp[j]=a[j-i];
					else
					tmp[j]='d';
				}
			}
			if (check(tmp))
			ans="Yes\n"+tmp;
		}
		cout << ans << endl;
	}
}
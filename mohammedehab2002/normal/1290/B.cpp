#include <bits/stdc++.h>
using namespace std;
int nex[26][200005];
int main()
{
	int q;
	string s;
	cin >> s >> q;
	for (int i=0;i<26;i++)
	nex[i][s.size()]=s.size();
	for (int i=s.size()-1;i>=0;i--)
	{
		for (int j=0;j<26;j++)
		nex[j][i]=nex[j][i+1];
		nex[s[i]-'a'][i]=i;
	}
	while (q--)
	{
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		if (l==r || s[l]!=s[r])
		cout << "YES" << endl;
		else
		{
			int cnt=0;
			for (int i=0;i<26;i++)
			cnt+=(nex[i][l]<=r);
			if (cnt<3)
			cout << "NO" << endl;
			else
			cout << "YES" << endl;
		}
	}
}
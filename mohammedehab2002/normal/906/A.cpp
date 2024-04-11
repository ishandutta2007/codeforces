#include <iostream>
#include <string.h>
using namespace std;
bool ok[26],aux[26];
int main()
{
	int ans=0;
	memset(ok,1,sizeof(ok));
	int n;
	cin >> n;
	while (n--)
	{
		int cnt=0,t;
		for (int i=0;i<26;i++)
		{
			if (ok[i])
			cnt++,t=i;
		}
		memset(aux,0,sizeof(aux));
		char c;
		string s;
		cin >> c >> s;
		for (int i=0;i<s.size();i++)
		aux[s[i]-'a']=1;
		if (cnt==1)
		{
			if ((c!='?' && aux[t]) || (c=='?' && !aux[t]))
			ans++;
			continue;
		}
		if (c=='!')
		{
			for (int i=0;i<26;i++)
			ok[i]&=aux[i];
		}
		else if (c=='.')
		{
			for (int i=0;i<26;i++)
			ok[i]&=(!aux[i]);
		}
		else
		ok[s[0]-'a']=0;
	}
	cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int h1[500010],h2[500010];
char c[500010];
int main()
{
	int T;cin>>T;int ans=0;
	while (T--)
	{
		cin>>c;int s1=0,s2=0,ll=strlen(c);
		for (int i=0;i<ll;i++)
		{
			if (c[i]=='(') s1++;
			else if (c[i]==')' && s1) s1--;
			else s2++;
		}
		if (s1 && s2) continue;
		if (!s1 && !s2) h1[0]++;
		else if (s1) h1[s1]++;else h2[s2]++;
	}
	ans=h1[0]/2;
	for (int i=1;i<=500000;i++) ans+=min(h1[i],h2[i]);
	cout<<ans;
}
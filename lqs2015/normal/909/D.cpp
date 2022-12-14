#include<bits/stdc++.h>
using namespace std;
char s[1111111];
int c[1111111],pre[1111111],nxt[1111111],n,ans,pp,nn;
vector<int> v,tv;
void check(int x)
{
	if (pre[x] && c[pre[x]]!=c[x]) 
	{
		v.push_back(x);
		return;
	}
	if (nxt[x]!=n+1 && c[nxt[x]]!=c[x]) 
	{
		v.push_back(x);
		return;
	}
}
void gao(int pp,int nn)
{
	nxt[pp]=nn;
	pre[nn]=pp;
	if (pp>=1 && pp<=n) check(pp);
	if (nn>=1 && nn<=n) check(nn);
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=1;i<=n;i++) c[i]=s[i-1]-'a'+1;
	for (int i=0;i<=n+1;i++) 
	{
		pre[i]=i-1;nxt[i]=i+1;
	}
	for (int i=1;i<=n;i++) 
	{
		check(i);
	}
	while(!v.empty())
	{
		ans++;
		tv=v;v.clear();pp=pre[tv[0]];
		for (int i=1;i<tv.size();i++)
		{
			if (nxt[tv[i-1]]==tv[i]) continue;
			nn=nxt[tv[i-1]];
			gao(pp,nn);pp=pre[tv[i]];
		}
		nn=nxt[tv[(int)tv.size()-1]];
		gao(pp,nn);
		v.resize(unique(v.begin(),v.end())-v.begin());
	}
	printf("%d\n",ans);
	return 0;
}
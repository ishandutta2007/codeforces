#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[222222],b[222222],son[222222][26],fail[222222],dep[222222],sz,pos,num[222222];
long long ans;
string t,s[222222];
queue<int> q;
void solve()
{
	memset(fail,0,sizeof(fail));memset(dep,0,sizeof(dep));sz=0;memset(son,0,sizeof(son));
	memset(num,0,sizeof(num));memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++)
	{
		pos=0;
		for (int j=0;j<s[i].size();j++)
		{
			if (son[pos][s[i][j]-'a'])
			{
				pos=son[pos][s[i][j]-'a'];
			}
			else
			{
				pos=son[pos][s[i][j]-'a']=++sz;
			}
		}
		num[pos]++;
	}
	for (int i=0;i<26;i++)
	{
		if (son[0][i])
		{
			fail[son[0][i]]=0;
			q.push(son[0][i]); 
			dep[son[0][i]]=num[son[0][i]];
		}
	}
	dep[0]=num[0];
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<26;i++)
		{
			if (son[x][i])
			{
				fail[son[x][i]]=son[fail[x]][i];
				dep[son[x][i]]=num[son[x][i]]+dep[son[fail[x]][i]];
				q.push(son[x][i]); 
			}
			else son[x][i]=son[fail[x]][i];
		}
	}
	pos=0;
	for (int i=0;i<t.size();i++)
	{
		pos=son[pos][t[i]-'a'];
		a[i]=dep[pos];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i];
	solve();
	for (int i=0;i<t.size();i++) b[i]=a[i];
	reverse(t.begin(),t.end());
	for (int i=1;i<=n;i++)
	{
		reverse(s[i].begin(),s[i].end());
	}
	solve();
	for (int i=0;i<(int)t.size()-1;i++)
	{
		ans+=(1ll*a[i]*b[(int)t.size()-2-i]);
	}
	printf("%lld\n",ans);
	return Accepted;
}
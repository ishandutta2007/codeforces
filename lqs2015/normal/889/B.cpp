#include<bits/stdc++.h>
using namespace std;
string s[111111],ans[111111],a[111111];
int n,pos[33],cnt;
bool used[33],u[111111];
bool In(string &a,string &b)
{
	for (int i=0;i<=(int)b.size()-(int)a.size();i++)
	{
		bool f=0;
		for (int j=i,k=0;k<a.size();j++,k++)
		{
			if (b[j]!=a[k]) 
			{
				f=1;
				break;
			}
		}
		if (!f) return 1;
	}
	return 0;
}
bool check(string &s)
{
	memset(used,0,sizeof(used));
	for (int i=0;i<s.size();i++)
	{
		if (used[s[i]-'a']) return 0;
		used[s[i]-'a']=1;
	}
	return 1;
}
string merge(string &a,string &b)
{
	if (In(a,b)) return b;
	if (In(b,a)) return a;
	string ans;int pos=-1;
	for (int i=(int)a.size()-1,j=0;j<b.size() && i>=0;i--,j++)
	{
		bool f=0;
		for (int k=i;k<a.size();k++)
		{
			if (a[k]!=b[k-i]) 
			{
				f=1;
				break;
			}
		}
		if (!f) pos=j;
	}
	ans=a;
	for (int j=pos+1;j<b.size();j++) ans=ans+b[j];
	if (check(ans)) return ans;
	pos=-1;
	for (int i=0,j=(int)b.size()-1;j>=0 && i<a.size();i++,j--)
	{
		bool f=0;
		for (int k=j;k<b.size();k++)
		{
			if (a[k-j]!=b[k]) 
			{
				f=1;
				break;
			}
		}
		if (!f) pos=i;
	}
	ans=b;
	for (int j=pos+1;j<a.size();j++) ans=ans+a[j];
	if (check(ans)) return ans;
	printf("NO\n");
	exit(0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		for (int j=0;j<s[i].size();j++)
		{
			if (used[s[i][j]-'a']) 
			{
				printf("NO\n");
				return 0;
			}
			used[s[i][j]-'a']=1;
		}
	}
	ans[1]=s[1];
	for (int i=0;i<s[1].size();i++) pos[s[1][i]-'a']=1;
	for (int i=2;i<=n;i++)
	{
		ans[i]=s[i];
		for (int j=0;j<s[i].size();j++)
		{
			if (pos[s[i][j]-'a'])
			{
				ans[i]=merge(ans[i],ans[pos[s[i][j]-'a']]);
				u[pos[s[i][j]-'a']]=1;
				int x=pos[s[i][j]-'a'];
				for (int k=0;k<ans[x].size();k++) pos[ans[x][k]-'a']=0;
			}
		}
		for (int k=0;k<ans[i].size();k++) pos[ans[i][k]-'a']=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (!u[i]) a[++cnt]=ans[i];
	}
	sort(a+1,a+cnt+1);
	for (int i=1;i<=cnt;i++) cout<<a[i];
	cout<<endl;
	return 0;
}
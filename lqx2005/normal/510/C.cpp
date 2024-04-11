#include<bits/stdc++.h>
using namespace std;
const int N=1000;
string s[N+5];
vector<int> g[N+5];
int deg[N+5];
int n;
vector<int> t;
bool flag;
void add(int u,int v)
{
	g[u].push_back(v);
	deg[v]++;
	return;
}
void check(string s,string t)
{
	int slen=s.length();
	int tlen=t.length();
	int len=min(slen,tlen);
	for(int i=0;i<len;i++)
	{
		if(s[i]!=t[i])
		{
			add(s[i]-'a',t[i]-'a');
			return;
		}
	}
	if(slen>tlen) 
	{
		flag=1;
		return;
	}
	return;
}
bool topsort()
{
	queue<int> q;
	for(int i=0;i<=25;i++) if(deg[i]==0) q.push(i);
	int tot=0;
	while(!q.empty())
	{
		tot++;
		int u=q.front();
		t.push_back(u);
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			deg[v]--;
			if(deg[v]==0)
			{
				q.push(v);
			}
		}
	}
	return tot!=26;
}
int main()
{
	scanf("%d",&n);
	flag=0;
	for(int i=1;i<=n;i++)  cin>>s[i];
	for(int i=2;i<=n;i++) check(s[i-1],s[i]);
	if(flag) 
	{
		printf("Impossible");
		return 0;
	}
	if(topsort()) printf("Impossible");
	else for(int i=0;i<t.size();i++) cout<<(char)(t[i]+'a');
	cout<<endl;
	return 0;
}
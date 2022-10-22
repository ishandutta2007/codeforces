#include <bits/stdc++.h>
using namespace std;
bool m=true;
int n;
vector<char> a[100005];
char st[100005];
int r[26];
int pl[26];
int l[100005];
vector<pair<int,int> > s[26];
int p[26];
vector<int> d;
bool vs[26];
bool rt[26];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",st);
		l[i]=strlen(st);
		for(int j=0;j<l[i];j++)
		{
			a[i].push_back(st[j]);
			p[st[j]-'a']++;
			if(p[st[j]-'a']>=2) m=false;
			else s[st[j]-'a'].push_back(make_pair(i,j));
		}
		for(int j=0;j<26;j++) p[j]=0;
	}
	if(!m)
	{
		printf("NO");
		return 0;
	}
	int u,v;
	int nl;
	int cl;
	for(int i=0;i<26;i++)
	{
		r[i]=-1;
		pl[i]=-1;
	}
	for(int i=0;i<26;i++)
	{
		cl=-1;
		for(int j=0;j<s[i].size();j++)
		{
			rt[i]=true;
			u=s[i][j].first;
			v=s[i][j].second;
			if(l[u]!=v+1)
			{
				nl=a[u][v+1]-'a';
				//cout<<u<<" "<<v<<" "<<nl<<" "<<cl<<endl;
				if(!((r[nl]>=0 && r[nl]!=i) || (cl>=0 && cl!=nl)))
				{
					r[nl]=i;
					pl[i]=nl;
					cl=nl;
				}
				else
				{
					printf("NO");
					return 0;
				}
			}
		}
	}
	int k;
	for(int i=0;i<26;i++)
	{	
		u=i;
		k=0;
		if(rt[i])
		{
			while(u!=-1)
			{
				k++;
				if(k>27)
				{
					printf("NO");
					return 0;
				}
				if(r[u]==-1 && !vs[u]) d.push_back(u);
				vs[u]=true;
				u=r[u];
			}
		}
	}
	sort(d.begin(),d.end());
	char sl;
	for(int i=0;i<d.size();i++)
	{
		u=d[i];
		while(u!=-1)
		{
			sl=u+'a';
			cout<<sl;
			u=pl[u];
		}
	}
	cout<<endl;
	return 0;
}
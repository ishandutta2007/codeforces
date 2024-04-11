#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
int n,m,k,lpos[555555],rpos[555555],pos,l,r,z[555555],zm[555555];
char s[555555],t[1111111],sr[555555],tr[1111111];
vector<int> v[555555];
multiset<int> se;
void z_function(char (&s)[555555],char (&t)[1111111])
{
	int szs,szt,l,r,j,k,pos=-1,sz;
	szs=strlen(s);szt=strlen(t);
	t[szt]='#';
	for (int i=0;i<szs;i++)
	{
		t[szt+i+1]=s[i];
	}
	t[szt+szs+1]='\0';sz=strlen(t);
	l=r=0;
	for (int i=1;i<sz;i++)
	{
		if (i>r)
		{
			for (j=0;j<sz;j++)
			{
				if (t[j]!=t[j+i]) break;
			}
			l=i;r=i+j-1;zm[i]=j;
		}
		else
		{
			k=i-l;
			if (zm[k]<r-i+1) 
			{
				zm[i]=zm[k];
			}
			else 
			{
				for (j=r;j<sz;j++)
				{
					if (t[j]!=t[j-i]) break;
				}
				l=i;r=j-1;zm[i]=r-l+1;
			}
		}
	}
	for (int i=szt+1;i<sz;i++)
	{
		z[i-szt-1]=zm[i];
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s,t);
	for (int i=n-1;i>=0;i--) sr[n-i-1]=s[i];
	for (int i=m-1;i>=0;i--) tr[m-i-1]=t[i];
	sr[n]='\0';tr[m]='\0';
	z_function(s,t);
	for (int i=0;i<n;i++)
	{
		v[z[i]].push_back(i); 
	}
	for (int i=0;i<=m;i++) lpos[i]=1e9;
	for (int i=m;i>=0;i--)
	{
		for (int j=0;j<v[i].size();j++) se.insert(v[i][j]);
		pos=k-i;
		if (se.empty()) continue;
		if (i==m) 
		{
			lpos[i]=*se.begin();
			continue;
		}
		if (pos>*se.rbegin()) continue;
		multiset<int>::iterator it=se.lower_bound(pos);
		lpos[i]=*it;
	}
	z_function(sr,tr);
	for (int i=0;i<n;i++) v[i].clear();
	for (int i=0;i<n;i++)
	{
		v[z[i]].push_back(i); 
	}
	for (int i=0;i<=m;i++) rpos[i]=1e9;
	se.clear();
	for (int i=m;i>=0;i--)
	{
		for (int j=0;j<v[i].size();j++) se.insert(v[i][j]);
		pos=k-i;
		if (se.empty()) continue;
		if (i==m) 
		{
			rpos[i]=*se.begin();
			continue;
		}
		if (pos>*se.rbegin()) continue;
		multiset<int>::iterator it=se.lower_bound(pos);
		rpos[i]=*it;
	}
	for (int i=0;i<=m;i++)
	{
		if (i>k || m-i>k) continue;
		l=lpos[i]+i-k+1;r=n-rpos[m-i]-m+i+1;
		if (i==m && l<=0) l=1;
		if (i==0 && r+k-1>n) r=n-k+1;
		if (l<=0 || r+k-1>n) continue;
		if (l+k<=r) 
		{
			printf("Yes\n");
			printf("%d %d\n",l,r);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[100005];
void ask(vector<int>v1,vector<int>v2)
{
	printf("? %d ",v1.size()+v2.size());
	for(int i=0;i<v1.size();i++)printf("%d ",v1[i]);
	for(int i=0;i<v2.size();i++)printf("%d ",v2[i]);
	printf("\n");
	fflush(stdout);
}
vector<int> hebing(vector<int>v1,vector<int>v2)
{
	for(int i=0;i<v2.size();i++)v1.push_back(v2[i]);
	return v1;
}
void solve(vector<int>v)
{
	if(v.size()<=2)
	{
		printf("! %d\n",v[0]);
		fflush(stdout);
		scanf("%s",s+1);
		if(s[2]==')')return;
		printf("! %d\n",v[1]);
		fflush(stdout);
		scanf("%s",s+1);
		if(s[2]==')')return;
		return;
	}
	vector<int>v1,v2,v3;
	for(int i=0;i<v.size();i++)
	{
		if(i%3==0)v1.push_back(v[i]);
		if(i%3==1)v2.push_back(v[i]);
		if(i%3==2)v3.push_back(v[i]);
	}
	ask(v1,v2);
	scanf("%s",s+1);
	if(s[1]=='Y')
	{
		ask(v1,v2);
		scanf("%s",s+1);
		if(s[1]=='Y')
		{
			solve(hebing(v1,v2));
			return;
		}
		ask(v1,v3);
		scanf("%s",s+1);
		if(s[1]=='Y')
		{
			solve(hebing(v1,v3));
			return;
		}
		else
		{
			solve(hebing(v2,v3));
			return;
		}
		return;
	}
	else
	{
		ask(v1,v3);
		scanf("%s",s+1);
		if(s[1]=='N')
		{
			solve(hebing(v2,v3));
			return;
		}
		solve(hebing(v1,v3));
		return;
	}
}
signed main()
{
	int t,n,k,ans;
	n=read();
	vector<int>v;
	for(int i=1;i<=n;i++)v.push_back(i); 
	solve(v);
	return 0;
}
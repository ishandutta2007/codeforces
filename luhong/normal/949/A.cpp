#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
char s[200010];
int ans=0,a[200100];
vector<int> v[200100];
int q1[200100],h1=0,t1=0,q2[200100],h2=0,t2=0;
int main()
{
	scanf("%s",s);int len=strlen(s);//cout<<len;
	for(int i=0;i<len;i++)a[i+1]=s[i]-'0';
	int cnt=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==0)
			if(h2<t2)q1[t1++]=q2[h2],v[q2[h2++]].push_back(i);
			else q1[t1++]=++cnt,v[cnt].push_back(i); 
		else if(h1<t1)q2[t2++]=q1[h1],v[q1[h1++]].push_back(i); 
			else return 0*puts("-1");
	}
	if(h2<t2)return 0*puts("-1");
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",v[i].size());
		for(int j=0;j<v[i].size();j++)printf("%d ",v[i][j]);
		puts("");
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=10010;
const int MaxM=1000010;

int n,m;
char s[MaxN],t[MaxM];
int p[MaxN][26],v[26];

void init()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=n;i>=0;--i)
	{
		for (int j=0;j<26;++j)
			p[i][j]=v[j];
		if (!i) break;
		v[s[i]-'a']=i;
	}
}

void work()
{
	int ans=0,now=0;
	for (int i=1;i<=m;++i)
	{
		int x=t[i]-'a';
		if (!p[0][x])
		{
			puts("-1");
			return;
		}
		if (now)
		{
			if (p[now][x])
			{
				now=p[now][x];
				continue;
			}
			now=0;
		}
		if (!now)
		{
			++ans;
			now=p[now][x];
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
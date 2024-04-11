#include <bits/stdc++.h>
using namespace std;
char a[2];
char s[200000];
bool sl[27];
int p[27];
bool u=false;
bool bc=false;
int n;
int t;
int m;
int r;
int main()
{
	for(int i=0;i<26;i++) p[i]=1; //moze svako slovo
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",a,s);
		m=strlen(s);
		for(int i=0;i<26;i++) sl[i]=false;
		for(int i=0;i<m;i++) sl[s[i]-'a']=true;
		if(a[0]=='?')
		{
			if(u)
			{
				if(s[0]-'a'!=t) r++;
			}
			else
			{
				p[s[0]-'a']=0;
			}
		}
		if(a[0]=='.')
		{
			if(!u)
			{
				for(int i=0;i<26;i++) if(sl[i]) p[i]=0;
			}
		}
		if(a[0]=='!')
		{
			if(u) r++;
			else
			{
				for(int i=0;i<26;i++)
				{
					if(sl[i])
					{
						if(p[i]!=0) p[i]=1;
					}
					else p[i]=0;
				}
			}
		}
		for(int i=0;i<26;i++)
		{
			if(p[i]==1) bc=true;
		}
		//cout<<u<<endl;
		if(!u)
		{
			for(int i=0;i<26;i++)
			{
				if(p[i]==1 && bc)
				{
					if(u)
					{
						u=false;
						i=26;
					}
					else u=true;
				}
			}
			if(u)
			{
				for(int i=0;i<26;i++) if(p[i]==1 && bc) t=i;
			}
		}
		//cout<<r<<" "<<u<<endl;
	}
	printf("%d",r);
	return 0;
}
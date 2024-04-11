#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int str_int(string &s)
{
	if (s[0]=='0') return -315;
	int res=0;
	for (int i=0;i<s.size();i++)
	{
		if (!isdigit(s[i])) return -315;
		res=res*10+(s[i]-'0');
	}
	return res;
}
int n,sz,p[111111],tp[111111],e,ke[111111],kp[111111],cnte,cntp,cnt;
int ans,zze,zzp,pos;
pair<int,int> anss[111111];
string s[111111];
char str[111111][11];
bool f,used[111111];
queue<int> ne,np;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s %d",str[i],&tp[i]);
		sz=strlen(str[i]);
		for (int j=0;j<sz;j++)
		{
			s[i]=s[i]+str[i][j];
		}
		p[i]=str_int(s[i]);
		if (tp[i]) e++;
	}
	for (int i=1;i<=n;i++)
	{
		if (tp[i] && p[i]>=e+1 && p[i]<=n) ke[++cnte]=i;
		if (!tp[i] && p[i]>=1 && p[i]<=e) kp[++cntp]=i;
 	}
 	for (int i=1;i<=n;i++)
 	{
 		if (p[i]>=1 && p[i]<=n) cnt++;
	}
	if (cnt==n)
	{
		if (!cnte && !cntp) 
		{
			cout<<0<<endl;
			return 0;
		}
		anss[++ans]=make_pair(ke[1],n+1);
		pos=p[ke[1]];f=0;zze=2;zzp=1;
		while(zzp<=cntp || zze<=cnte)
		{
			if (!f)
			{
				anss[++ans]=make_pair(kp[zzp++],pos);
				pos=p[kp[zzp-1]];
			}
			else
			{
				anss[++ans]=make_pair(ke[zze++],pos);
				pos=p[ke[zze-1]];
			}
			f=!f;
		}
		printf("%d\n",ans+1);
		for (int i=1;i<=ans;i++)
		{
			printf("move %s %d\n",str[anss[i].first],anss[i].second);
		}
		printf("move %d %d\n",n+1,pos);
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (p[i]>=1 && p[i]<=n) used[p[i]]=1;
		}
		for (int i=1;i<=e;i++) 
		{
			if (!used[i]) ne.push(i); 
		}
		for (int i=e+1;i<=n;i++)
		{
			if (!used[i]) np.push(i); 
		}
		zze=zzp=1;
		while(zze<=cnte || zzp<=cntp)
		{
			if (!f)
			{
				while(!ne.empty() && zze<=cnte)
				{
					anss[++ans]=make_pair(ke[zze++],ne.front());
					ne.pop();
					np.push(p[ke[zze-1]]); 
				}
			}
			else
			{
				while(!np.empty() && zzp<=cntp)
				{
					anss[++ans]=make_pair(kp[zzp++],np.front());
					np.pop();
					ne.push(p[kp[zzp-1]]); 
				}
			}
			f=!f;
		}
		for (int i=1;i<=n;i++)
		{
			if (p[i]>=1 && p[i]<=n) continue;
			if (tp[i])
			{
				anss[++ans]=make_pair(i,ne.front());
				ne.pop();
			}
			else
			{
				anss[++ans]=make_pair(i,np.front());
				np.pop();
			}
		}
		printf("%d\n",ans);
		for (int i=1;i<=ans;i++)
		{
			printf("move %s %d\n",str[anss[i].first],anss[i].second);
		}
	}
	return 0;
}
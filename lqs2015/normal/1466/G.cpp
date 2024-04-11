#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7,iv=(mod+1)/2;
int q,n,pw[222222],sz,fun[2222222],m,len,id,pos,all,ans,crt,z1[2222222],z2[2222222],allen,cc,cp;
int sum[26][111111];
bool flg;
char s[111],t[111111],str[1111111],prt[1111111],cur[2222222];
void genz(int z[],char s[],int sz)
{
	int l,r,j,k;
	l=0;r=0;
	for (int i=1;i<sz;i++)
	{
		if (i>r)
		{
			for (j=0;j<sz;j++)
			{
				if (s[j]!=s[j+i]) break;
			}
			l=i;r=i+j-1;z[i]=j;
		}
		else
		{
			k=i-l;
			if (z[k]<r-i+1) 
			{
				z[i]=z[k];
			}
			else 
			{
				for (j=r;j<sz;j++)
				{
					if (s[j]!=s[j-i]) break;
				}
				l=i;r=j-1;z[i]=r-l+1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	pw[0]=1;
	for (int i=1;i<=200000;i++) pw[i]=(pw[i-1]+pw[i-1])%mod;
	for (int i=0;i<=20;i++) fun[1<<i]=i;
	scanf("%s",s);
	scanf("%s",t);
	m=strlen(s);
	for (int i=0;i<26;i++)
	{
		cp=iv;
		if (t[0]-'a'==i) sum[i][0]=1;
		else sum[i][0]=0;
		for (int j=1;j<n;j++)
		{
			if (t[j]-'a'==i) sum[i][j]=(sum[i][j-1]+cp)%mod;
			else sum[i][j]=sum[i][j-1];
			cp=1ll*cp*iv%mod;
		}
	}
	while(q--)
	{
		scanf("%d",&id);
		scanf("%s",str);len=strlen(str);
		ans=0;
		for (int i=0;i<=m && i<len;i++)
		{
			flg=0;
			for (int j=0;j<i;j++)
			{
				if (str[j]!=s[m-i+j]) 
				{
					flg=1;
					break;
				}
			}
			pos=i;all=0;
			while(pos<len && !flg)
			{
				prt[all++]=str[pos];
				for (int j=pos+1;j<=pos+m && j<len;j++)
				{
					if (str[j]!=s[j-pos-1]) 
					{
						flg=1;
						break;
					}
				}
				pos+=(m+1);
			}
			if (flg) continue;
			sz=1;crt=0;
			while(sz<all)
			{
				sz<<=1;
				crt++;
			}
			allen=0;
			for (int j=1;j<sz;j++)
			{
				if (fun[j&(-j)]>=id) cur[allen++]='#';
				else cur[allen++]=t[fun[j&(-j)]];
			}
			for (int j=0;j<all;j++) cur[allen++]=prt[j];
			genz(z1,cur,allen);
			allen=0;
			for (int j=0;j<all;j++) cur[allen++]=prt[j];
			for (int j=1;j<sz;j++)
			{
				if (fun[j&(-j)]>=id) cur[allen++]='#';
				else cur[allen++]=t[fun[j&(-j)]];
			}
			genz(z2,cur,allen);
			for (int j=0;j<sz;j++)
			{
				if (j && j+all<=sz)
				{
					if (z2[all+j-1]>=all) 
					{
						if (id-crt>=0)
						{
							ans=(ans+pw[id-crt])%mod;
						}
					}
				}
				else
				{
					flg=0;pos=1;
					if (j)
					{
						if (z2[all+j-1]<sz-j) flg=1;
						pos=sz-j+1;
					}
					if (z1[sz-1+pos]<all-pos) flg=1;
					if (!flg) 
					{
						cc=prt[pos-1]-'a';
						if (crt<=id-1)
						{
							if (crt) ans=(1ll*pw[id-1]*(sum[cc][id-1]-sum[cc][crt-1])+ans)%mod;
							else ans=(1ll*pw[id-1]*sum[cc][id-1]+ans)%mod;
						}
					}
				}
			}
		}
		for (int i=0;i+len<=m;i++)
		{
			flg=0;
			for (int j=0;j<len;j++)
			{
				if (str[j]!=s[j+i]) 
				{
					flg=1;
					break;
				}
			}
			if (!flg) ans=(ans+pw[id])%mod;
		}
		printf("%d\n",(ans+mod)%mod);
	}
	return Accepted;
}
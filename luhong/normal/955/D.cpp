#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int nxt[500100],id[500100];char s[500100],t[500100];
int L[500100],R[500100];
void init(char *s)
{
	nxt[0]=-1;int len=strlen(s);
	int i=0,j=-1;
	while(i<len)
	{
		if(j==-1||s[i]==s[j])
		{
			i++;j++;nxt[i]=j;
		}
		else
		{
			j=nxt[j];
		}
	}
}
int kmp(char *s,char *t,int l)
{
	int lens=strlen(s),lent=strlen(t);int r=lent-1;
	int j=0,i=0;
	while(i<lens)
	{
		if(j==-1||s[i]==t[j])
		{
			if(j!=-1&&i>=l&&id[j]==-1)r=min(r,j-1),id[j]=i;
			i++;j++;
		}
		else 
		{
			if(i-1>=l){for(int o=max(0,j-(i-l));o<=min(j-1,r);o++)if(id[o]==-1)id[o]=i-(j-o);r=min(r,max(0,j-(i-l))-1);}
			j=nxt[j];
		}
		if(j==lent)return i;
	}
	return -1;
}
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s);scanf("%s",t);init(t);
	memset(id,-1,sizeof(id));int ok=kmp(s,t,k-1);
	if(ok!=-1)
	{
		for(int i=0;i<n;i++)if(i+k+k>=ok)return 0*printf("Yes\n%d %d",i+1,i+k+1);
	}
	for(int i=0;i<m;i++)L[i]=id[i];
	for(int i=0;i<(n>>1);i++)swap(s[i],s[n-i-1]);
	for(int i=0;i<(m>>1);i++)swap(t[i],t[m-i-1]);
	memset(nxt,-1,sizeof(nxt));memset(id,-1,sizeof(id));
	init(t);kmp(s,t,k-1);
	for(int i=0;i<m;i++)R[m-i-1]=(id[i]==-1?-1:n-id[i]-1);
	for(int i=max(0,m-k-1);i<min(k,m-1);i++)
	{
		if(L[i]!=-1&&R[i+1]!=-1&&R[i+1]>L[i])return 0*printf("Yes\n%d %d",L[i]-k+2,R[i+1]+1);
	}
	return 0*puts("No");
}
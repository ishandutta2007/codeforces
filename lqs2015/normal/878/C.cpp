#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
struct scc
{
	int mx[11],mn[11],sum;
}key[111111];
int f[111111],ch[111111][2],sz[111111],mxx[111111][11],mnn[111111][11],sum[111111],rt,szz;
int b[11],l,r;
bool can_beat(int cur[],int x[])
{
	for (int i=1;i<=k;i++)
	{
		if (cur[i]<x[i]) return 0;
	}
	return 1;
}
void clear(int x)
{
    f[x]=ch[x][0]=ch[x][1]=sz[x]=sum[x]=0;
    for (int i=1;i<=k;i++) mxx[x][i]=mnn[x][i]=0;
}
int get(int x)
{
    return (ch[f[x]][1]==x);
}
void pushup(int x)
{
    sz[x]=1;sum[x]=key[x].sum;
    for (int i=1;i<=k;i++) mxx[x][i]=key[x].mx[i];
    for (int i=1;i<=k;i++) mnn[x][i]=key[x].mn[i];
    if (ch[x][0])
    {
    	sz[x]+=sz[ch[x][0]];
    	sum[x]+=sum[ch[x][0]];
    	for (int i=1;i<=k;i++)
    	{
    		mxx[x][i]=max(mxx[x][i],mxx[ch[x][0]][i]);
    		mnn[x][i]=min(mnn[x][i],mnn[ch[x][0]][i]);
		}
	}
	if (ch[x][1])
	{
		sz[x]+=sz[ch[x][1]];
    	sum[x]+=sum[ch[x][1]];
    	for (int i=1;i<=k;i++)
    	{
    		mxx[x][i]=max(mxx[x][i],mxx[ch[x][1]][i]);
    		mnn[x][i]=min(mnn[x][i],mnn[ch[x][1]][i]);
		}
	}
}
void rotate(int x)
{
    int fa=f[x],gfa=f[fa],wh=get(x);
    ch[fa][wh]=ch[x][wh^1];
    f[ch[x][wh^1]]=fa;
    ch[x][wh^1]=fa;
    f[fa]=x;
    if (gfa) ch[gfa][ch[gfa][1]==fa]=x;
    f[x]=gfa;
    pushup(fa);pushup(x);
}
void splay(int x,int goal)
{
    for (int fa;(fa=f[x])!=goal;rotate(x))
    {
        if (f[fa]!=goal)
        {
            if (get(fa)==get(x)) rotate(fa);
            else rotate(x);
        }
    }
    if (!goal) rt=x;
}
int find(int x)
{
    int pos=rt;
    while(1)
    {
        if (x<=sz[ch[pos][0]]) pos=ch[pos][0];
        else
        {
            if (x==sz[ch[pos][0]]+1) return pos;
            x-=(sz[ch[pos][0]]+1);
            pos=ch[pos][1];
        }
    }
}
int findl(int b[])
{
    int pos=rt,res=0;
    while(pos)
    {
    	if (can_beat(key[pos].mn,b)) 
		{
			res+=(1+sz[ch[pos][0]]);
			pos=ch[pos][1];
		}
		else pos=ch[pos][0];
	}
	return res+1;
}
int findr(int b[])
{
    int pos=rt,res=0;
    while(pos)
    {
    	if (can_beat(b,key[pos].mx)) pos=ch[pos][0];
		else
		{
			res+=(1+sz[ch[pos][0]]);
			pos=ch[pos][1];
		}
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	szz=2;
	for (int i=1;i<=k;i++)
	{
		key[1].mx[i]=key[1].mn[i]=mxx[1][i]=mnn[1][i]=mxx[2][i]=2e9;
		key[2].mx[i]=key[2].mn[i]=mnn[2][i]=-2e9;
	}
	ch[2][0]=1;rt=2;sum[2]=2;sum[1]=1;f[1]=2;
	key[1].sum=key[2].sum=1;sz[1]=1;sz[2]=2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			scanf("%d",&b[j]);
		}
		l=findl(b);r=findr(b);
		if (l>r)
		{
			l=find(l);r=find(r);
			splay(r,0);
			splay(l,r);
			szz++;
			for (int j=1;j<=k;j++) key[szz].mn[j]=key[szz].mx[j]=b[j];
			key[szz].sum=1;
			f[szz]=ch[rt][1];
			ch[ch[rt][1]][0]=szz;
			pushup(ch[ch[rt][1]][0]);pushup(ch[rt][1]);pushup(rt);
		}
		else
		{
			l=find(l-1);r=find(r+1);
			splay(l,0);splay(r,l);
			int x=ch[ch[rt][1]][0];
			for (int j=1;j<=k;j++)
			{
				key[x].mx[j]=max(mxx[x][j],b[j]);
				key[x].mn[j]=min(mnn[x][j],b[j]);
			}
			clear(ch[x][0]);clear(ch[x][1]);
			key[x].sum=sum[x]+1;ch[x][0]=ch[x][1]=0;
			pushup(x);pushup(ch[rt][1]);pushup(rt);
		}
		l=find(2);
		printf("%d\n",key[l].sum);
		splay(l,0);
	}
	return 0;
}